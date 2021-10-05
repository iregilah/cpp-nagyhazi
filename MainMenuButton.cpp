#include "MainMenuButton.h"
#include "GameStateHandler.h"
#include "MainMenuState.h"
#include "Defines.h"


void MainMenuButton::render(SDL_Renderer *renderer){
    texture.render(renderer, location);
}

void MainMenuButton::click() const{
    GameStateHandler::getInstance().updateState(std::make_unique<MainMenuState>());
}

Texture MainMenuButton::texture{Defines::TexturePaths::Buttons::MENU};