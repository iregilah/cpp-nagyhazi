#ifndef AKNAKERESO_MAINMENUSTATE_H
#define AKNAKERESO_MAINMENUSTATE_H

#include <memory>
#include <array>
#include "GameState.h"
#include "Button.h"
#include "Texture.h"

class MainMenuState : public GameState {
private:
    std::array<std::unique_ptr<Button>,2> buttons;
    static Texture logo;
public:
    MainMenuState();

    void click(const SDL_Event &clickEvent) override;

    void render(SDL_Renderer *renderer) override;

};


#endif //AKNAKERESO_MAINMENUSTATE_H
