#ifndef AKNAKERESO_EXITBUTTON_H
#define AKNAKERESO_EXITBUTTON_H
#include "Button.h"
#include "Texture.h"

class ExitButton : public Button{
public:
    void render(SDL_Renderer *renderer) override;
    //TODO Kivit megkérdezni!!!
    using Button::Button;
protected:
    void click() const override;
private:
    static Texture texture;
};


#endif //AKNAKERESO_EXITBUTTON_H
