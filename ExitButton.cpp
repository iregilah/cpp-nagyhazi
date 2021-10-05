#include "ExitButton.h"
#include <SDL2/SDL.h>
#include "Defines.h"

void ExitButton::render(SDL_Renderer *renderer) {
    texture.render(renderer, location);
}

void ExitButton::click() const {
    SDL_Event quitEvent = {};
    quitEvent.type = SDL_QUIT;
    SDL_PushEvent(&quitEvent);
}

Texture ExitButton::texture{Defines::TexturePaths::Buttons::EXIT};