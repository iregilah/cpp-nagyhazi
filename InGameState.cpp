#include "InGameState.h"
#include "Defines.h"
#include "GameStateHandler.h"
#include "NewGameButton.h"
#include "ExitButton.h"

void InGameState::click(const SDL_Event &clickEvent) {
    SDL_Rect window = {};
    window.w = Defines::WINDOW_WIDTH;
    window.h = Defines::WINDOW_HEIGHT;
    if(dead){
        for(const auto& button: buttons) if(button->wasClicked(clickEvent)) return;
        return;
    }
    if(gameGrid.click(window,clickEvent)){
        // Felrobbantunk, game over.
        gameGrid.revealAll();
        dead = true;
    }
}

void InGameState::render(SDL_Renderer *renderer) {
    SDL_Rect window = {};
    window.w = Defines::WINDOW_WIDTH;
    window.h = Defines::WINDOW_HEIGHT;
    gameGrid.render(renderer, window);
    if(dead) for(const auto& button : buttons) button->render(renderer);
}

InGameState::InGameState(unsigned int width, unsigned int height, unsigned int mineCount) : gameGrid(width, height, mineCount) {
    const unsigned screenCenterX = Defines::WINDOW_WIDTH/2;
    const unsigned margin = 50;
    const unsigned buttonHeight = 50;
    const unsigned buttonWidth = 4*buttonHeight;

    SDL_Rect buttonPos = {};
    buttonPos.w = buttonWidth;
    buttonPos.h = buttonHeight;

    buttonPos.x = screenCenterX+margin;
    buttonPos.y = Defines::WINDOW_HEIGHT-buttonHeight-margin;
    buttons[0] = std::make_unique<NewGameButton>(buttonPos);
    buttonPos.x = screenCenterX-margin-buttonWidth;
    buttons[1] = std::make_unique<ExitButton>(buttonPos);
}
