#ifndef AKNAKERESO_MAINMENUBUTTON_H
#define AKNAKERESO_MAINMENUBUTTON_H
#include "Button.h"
#include "Texture.h"

class MainMenuButton : public Button{
public:
    void render(SDL_Renderer *renderer) override;
    using Button::Button;
protected:
    void click() const override;
private:
    static Texture texture;
};


#endif //AKNAKERESO_MAINMENUBUTTON_H
