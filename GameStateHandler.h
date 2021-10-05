#ifndef AKNAKERESO_GAMESTATEHANDLER_H
#define AKNAKERESO_GAMESTATEHANDLER_H
#include <memory>
#include "GameState.h"

class GameStateHandler {
protected:
    static std::unique_ptr<GameStateHandler> instance;

    std::unique_ptr<GameState> gameState;
    std::unique_ptr<GameState> newState;

    std::unique_ptr<GameState>& getState();
    GameStateHandler(); //TODO: Ezt valahogy protectedbe
public:

    GameStateHandler(const GameStateHandler&) = delete;
    void operator=(const GameStateHandler&) = delete;

    void click(const SDL_Event& clickEvent);
    void render(SDL_Renderer* renderer);

    void updateState(std::unique_ptr<GameState>&& newState);

    static GameStateHandler& getInstance();
};


#endif //AKNAKERESO_GAMESTATEHANDLER_H
