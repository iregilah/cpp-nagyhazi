#ifndef AKNAKERESO_NEXTBUTTON_H
#define AKNAKERESO_NEXTBUTTON_H
#include "Button.h"
#include "Texture.h"

class NextButton : public Button {
public:
    void render(SDL_Renderer *renderer) override;
    using Button::Button;
protected:
    void click() const override;
private:
    static Texture texture;
};


#endif //AKNAKERESO_NEXTBUTTON_H
