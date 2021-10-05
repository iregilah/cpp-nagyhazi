#include "NextButton.h"
#include "Defines.h"

void NextButton::render(SDL_Renderer *renderer) {
    texture.render(renderer, location);
}

// Csak azt ellenőrzi le, hogy rákattintottak-e
void NextButton::click() const {}

Texture NextButton::texture{Defines::TexturePaths::Buttons::NEXT};