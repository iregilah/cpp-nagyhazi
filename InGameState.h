#ifndef AKNAKERESO_INGAMESTATE_H
#define AKNAKERESO_INGAMESTATE_H
#include "GameState.h"
#include "GameGrid.h"
#include <array>
#include <memory>
#include "Button.h"

class InGameState : public GameState{
private:
    std::array<std::unique_ptr<Button>, 2> buttons;
    GameGrid gameGrid;
    bool dead = false;
public:
    InGameState(unsigned width, unsigned height, unsigned mineCount);

    void click(const SDL_Event &clickEvent) override;

    void render(SDL_Renderer *renderer) override;

};


#endif //AKNAKERESO_INGAMESTATE_H
