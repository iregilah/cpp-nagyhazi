#include "Button.h"

Button::Button(const SDL_Rect &location) : location(location){}

bool Button::wasClicked(const SDL_Event &clickEvent) {
    if(checkIsClicked(clickEvent)){
        click();
        return true;
    }
    return false;
}

bool Button::checkIsClicked(const SDL_Event &clickEvent) const{
    //A kattintás benne van-e a téglalapban
    if(clickEvent.button.x>location.x && clickEvent.button.x<location.x+location.w
       && clickEvent.button.y>location.y && clickEvent.button.y<location.y+location.h)
        return true;
    return false;
}
