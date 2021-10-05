#ifndef AKNAKERESO_GAMESTATE_H
#define AKNAKERESO_GAMESTATE_H

#include <SDL2/SDL.h>

//tárolni fogja, hogy jelenleg milyen állapotban van a program. játékállapot. Eztfogjuk változtatni, ha a menübe megyünk.
class GameState {
public:
    virtual void click(const SDL_Event& clickEvent) = 0;
    virtual void render(SDL_Renderer *renderer) = 0;
};



#endif //AKNAKERESO_GAMESTATE_H