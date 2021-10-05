//
// Created by iregilah on 2021. 05. 05..
//

#ifndef AKNAKERESO_BUTTON_H
#define AKNAKERESO_BUTTON_H
#include <SDL2/SDL.h>

// Egy gomb ami megjelenik az ablakban és rá lehet kattintani
class Button {
protected:
    const SDL_Rect location;

    // Leellenőrzi, hogy a clickEvent a gombon történt
    bool checkIsClicked(const SDL_Event& clickEvent) const;

    // Amit a kattintásnak csinálnia kell
    virtual void click() const = 0;
public:

    // Beállítja, hogy hol jelenjen meg a gomb.
    explicit Button(const SDL_Rect& location);

    // Ha a gombra kattintottunk, akkor meghívja a click() függvényt
    virtual bool wasClicked(const SDL_Event& clickEvent);

    // Kirajzolja a gombot
    virtual void render(SDL_Renderer* renderer) = 0;
};


#endif //AKNAKERESO_BUTTON_H
