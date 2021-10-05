#include "NewGameState.h"
#include "Defines.h"
#include "GameStateHandler.h"
#include "InGameState.h"
void NewGameState::click(const SDL_Event &clickEvent) {
    if(exitButton->wasClicked(clickEvent)) return;
    if(backButton->wasClicked(clickEvent)) return;
    if(gridWidth->wasClicked(clickEvent)) return;
    if(gridHeight->wasClicked(clickEvent)) return;
    if(mineCount->wasClicked(clickEvent)) return;

    if(nextButton->wasClicked(clickEvent)){
        auto width = gridWidth->getValue();
        auto height = gridHeight->getValue();
        auto mines = mineCount->getValue();
        GameStateHandler::getInstance().updateState(std::make_unique<InGameState>(width, height, mines));
    }
}

void NewGameState::render(SDL_Renderer *renderer) {
    exitButton->render(renderer);
    backButton->render(renderer);
    nextButton->render(renderer);
    gridWidth->render(renderer);
    gridHeight->render(renderer);
    mineCount->render(renderer);
}

NewGameState::NewGameState(){ //TODO: Lehet érdemes lenne tömböt használni?
    const unsigned screenCenterX = Defines::WINDOW_WIDTH/2;
    const unsigned screenCenterY = Defines::WINDOW_HEIGHT/2;
    const unsigned buttonHeight = 50;
    const unsigned buttonWidth = 4*buttonHeight;
    const unsigned margin = 50;

    SDL_Rect controlPosition = {};
    controlPosition.w = buttonWidth;
    controlPosition.h = buttonHeight;

    controlPosition.y = Defines::WINDOW_HEIGHT-margin-buttonHeight;
    controlPosition.x = Defines::WINDOW_WIDTH-buttonWidth-margin;
    nextButton = std::make_unique<NextButton>(controlPosition);

    controlPosition.x = margin;
    exitButton = std::make_unique<ExitButton>(controlPosition);

    controlPosition.y -= buttonHeight + margin;
    backButton = std::make_unique<MainMenuButton>(controlPosition);

    controlPosition.x = screenCenterX - buttonWidth-margin;
    controlPosition.y = screenCenterY-buttonHeight-margin/2;
    gridWidth = std::make_unique<ScrollBox>(controlPosition);

    controlPosition.y = screenCenterY+margin/2;
    gridHeight = std::make_unique<ScrollBox>(controlPosition);

    controlPosition.x = screenCenterX+margin;
    controlPosition.y = screenCenterY-buttonHeight/2;
    mineCount = std::make_unique<ScrollBox>(controlPosition,45);
}
