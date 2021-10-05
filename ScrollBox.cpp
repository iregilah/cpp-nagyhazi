#include "ScrollBox.h"
#include <stdexcept>
#include "Defines.h"

bool ScrollBox::wasClicked(const SDL_Event &clickEvent) {
    if (clickEvent.button.x < location.x || clickEvent.button.x > location.x + location.w
        || clickEvent.button.y < location.y || clickEvent.button.y > location.y + location.h)
        return false;
    const auto offsetX = clickEvent.button.x - location.x;
    if (offsetX > location.w - buttonWidth) {
        // Gombra kattintottunk
        const auto offsetY = clickEvent.button.y - location.y;
        if (offsetY > location.h / 2) {
            // Alsó gombra kattintottunk
            if(value>1)
                value--;
            else
                value = 100;
        } else {
            // Felső gombra kattintottunk
            if(value<100)
                value++;
            else
                value = 1;
        }
    }
}

void ScrollBox::render(SDL_Renderer *renderer) {
    SDL_Rect renderRect = {};
    // Render buttons

    renderRect.x = location.w + location.x - buttonWidth;
    renderRect.w = buttonWidth;
    renderRect.h = location.h / 2;

    // ^
    renderRect.y = location.y;
    upArrow.render(renderer, renderRect);

    // V
    renderRect.y = location.y + location.h / 2;
    downArrow.render(renderer, renderRect);

    // Render border
    SDL_SetRenderDrawColor(renderer, Defines::TexturePaths::Scroller::BORDER_COLOUR.r,
                           Defines::TexturePaths::Scroller::BORDER_COLOUR.g,
                           Defines::TexturePaths::Scroller::BORDER_COLOUR.b,
                           Defines::TexturePaths::Scroller::BORDER_COLOUR.a);
    SDL_RenderDrawRect(renderer, &location);

    renderRect.w = Defines::TexturePaths::NUMBER_WIDTH;
    renderRect.h = Defines::TexturePaths::NUMBER_HEIGHT;
    renderRect.y = location.y + location.h/2 - renderRect.h/2;

    auto numberToRender = toDecimal(value);
    for(int i=0;i<numberToRender.size();++i){
        renderRect.x = location.x + location.w - buttonWidth - renderRect.w*(i+1);
        numbers[numberToRender[i]].render(renderer, renderRect);
    }
}

ScrollBox::ScrollBox(const SDL_Rect &position, unsigned int startValue)
        : location(position), value(startValue) {
    if (location.w < buttonWidth)
        throw std::runtime_error("Scroll box too small!");
}

unsigned int ScrollBox::getValue() const {
    return value;
}

std::array<Texture, 10> ScrollBox::numbers = {
        Texture(Defines::TexturePaths::NUMBERS[0]),
        Texture(Defines::TexturePaths::NUMBERS[1]),
        Texture(Defines::TexturePaths::NUMBERS[2]),
        Texture(Defines::TexturePaths::NUMBERS[3]),
        Texture(Defines::TexturePaths::NUMBERS[4]),
        Texture(Defines::TexturePaths::NUMBERS[5]),
        Texture(Defines::TexturePaths::NUMBERS[6]),
        Texture(Defines::TexturePaths::NUMBERS[7]),
        Texture(Defines::TexturePaths::NUMBERS[8]),
        Texture(Defines::TexturePaths::NUMBERS[9])
};

Texture ScrollBox::upArrow{Defines::TexturePaths::Scroller::INCREMENT};
Texture ScrollBox::downArrow{Defines::TexturePaths::Scroller::DECREMENT};

std::vector<unsigned> ScrollBox::toDecimal(unsigned int value) {
    std::vector<unsigned> result;
    if(value == 0) {
        result.push_back(0);
        return result;
    }
    while(value){
        result.push_back(value%10);
        value/=10;
    }
    return result;
}
