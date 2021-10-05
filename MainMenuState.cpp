#include "MainMenuState.h"
#include "Defines.h"

#include "NewGameButton.h"
#include "ExitButton.h"

void MainMenuState::click(const SDL_Event &clickEvent) {
    for (const auto &button : buttons) {
        if (button->wasClicked(clickEvent))
            return;
    }
}

void MainMenuState::render(SDL_Renderer *renderer) {
    SDL_Rect logoPosition = {};
    logoPosition.w = Defines::TexturePaths::LOGO_W;
    logoPosition.h = Defines::TexturePaths::LOGO_H;
    logoPosition.y = 50;
    logoPosition.x = Defines::WINDOW_WIDTH/2-logoPosition.w/2;
    logo.render(renderer, logoPosition);
    for (const auto &button: buttons) {
        button->render(renderer);
    }
}

MainMenuState::MainMenuState() {
    const unsigned screenCenterX = Defines::WINDOW_WIDTH / 2;
    const unsigned screenCenterY = Defines::WINDOW_HEIGHT / 2;
    const unsigned buttonHeight = 100;
    const unsigned buttonWidth = 4 * buttonHeight;

    SDL_Rect buttonLocation = {};
    buttonLocation.x = screenCenterX - buttonWidth / 2;
    buttonLocation.y = screenCenterY - buttonHeight / 2;
    buttonLocation.w = buttonWidth;
    buttonLocation.h = buttonHeight;

    buttons[0] = std::make_unique<NewGameButton>(buttonLocation);

    buttonLocation.y = Defines::WINDOW_HEIGHT - buttonHeight * 2;
    buttons[1] = std::make_unique<ExitButton>(buttonLocation);
}

Texture MainMenuState::logo{Defines::TexturePaths::LOGO};