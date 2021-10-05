#include "GameStateHandler.h"
#include "MainMenuState.h"
#include <cassert>
std::unique_ptr<GameStateHandler> GameStateHandler::instance;

GameStateHandler &GameStateHandler::getInstance() {
    static GameStateHandler handler;
    return handler;
}

GameStateHandler::GameStateHandler() {
    gameState = std::make_unique<MainMenuState>();
}

void GameStateHandler::updateState(std::unique_ptr<GameState> &&newState) {
    this->newState = std::move(newState);
}

void GameStateHandler::render(SDL_Renderer *renderer) {
    getState()->render(renderer);
}

void GameStateHandler::click(const SDL_Event &clickEvent) {
    getState()->click(clickEvent);
}

std::unique_ptr<GameState> &GameStateHandler::getState() {
    if(newState){
        gameState = std::move(newState);
    }
    return gameState;
}
