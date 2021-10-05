#include "NewGameButton.h"
#include "GameStateHandler.h"
#include "NewGameState.h"
#include "Defines.h"

void NewGameButton::render(SDL_Renderer *renderer) {
    texture.render(renderer,location);
}

void NewGameButton::click() const {
    GameStateHandler::getInstance().updateState(std::make_unique<NewGameState>());
}

Texture NewGameButton::texture {Defines::TexturePaths::Buttons::NEW_GAME};