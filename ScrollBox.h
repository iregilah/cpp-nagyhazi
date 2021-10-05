#ifndef AKNAKERESO_SCROLLBOX_H
#define AKNAKERESO_SCROLLBOX_H

#include "SDL2/SDL.h"
#include <array>
#include <vector>
#include "Texture.h"

//  -------------------
//  | ---  ---  |  ^  |
//  |   |    |  | / \ |
//  | ---  ---  |-----|
//  |   |  |    | \ / |
//  | ---  ---  |  V  |
//  -------------------

class ScrollBox {
private:
    const SDL_Rect location;
    static constexpr int buttonWidth = 40;

    static std::array<Texture, 10> numbers;
    static Texture upArrow;
    static Texture downArrow;
    unsigned value;

    static std::vector<unsigned> toDecimal(unsigned value);
public:
    explicit ScrollBox(const SDL_Rect& position, unsigned startValue = 20);

    unsigned int getValue() const;

    bool wasClicked(const SDL_Event& clickEvent);
    void render(SDL_Renderer* renderer);
};


#endif //AKNAKERESO_SCROLLBOX_H
