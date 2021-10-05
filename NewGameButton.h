#ifndef AKNAKERESO_NEWGAMEBUTTON_H
#define AKNAKERESO_NEWGAMEBUTTON_H
#include "Button.h"
#include "Texture.h"

class NewGameButton : public Button {
public:
    void render(SDL_Renderer *renderer) override;
    using Button::Button; // Orokoljuk a konstruktort
protected:
    void click() const override;
private:
    static Texture texture;
};


#endif //AKNAKERESO_NEWGAMEBUTTON_H
