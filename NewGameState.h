#ifndef AKNAKERESO_NEWGAMESTATE_H
#define AKNAKERESO_NEWGAMESTATE_H
#include "GameState.h"

#include "ScrollBox.h"
#include "MainMenuButton.h"
#include "ExitButton.h"
#include "NextButton.h"

#include <memory>
#include <array>

class NewGameState : public GameState{
private:
    std::unique_ptr<ScrollBox> gridWidth;
    std::unique_ptr<ScrollBox> gridHeight;
    std::unique_ptr<ScrollBox> mineCount;

    std::unique_ptr<MainMenuButton> backButton;
    std::unique_ptr<ExitButton> exitButton;
    std::unique_ptr<NextButton> nextButton;
public:
    NewGameState();

    void click(const SDL_Event &clickEvent) override;

    void render(SDL_Renderer *renderer) override;

};


#endif //AKNAKERESO_NEWGAMESTATE_H
