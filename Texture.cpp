#include "Texture.h"
#include "SDL2/SDL_image.h"

#include <utility>
#include <cassert>
#include <stdexcept>

Texture::~Texture() {
    if(texture) SDL_DestroyTexture(texture);
}

Texture::Texture(std::string filePath) : filePath(std::move(filePath)){}

void Texture::render(SDL_Renderer *renderer, const SDL_Rect &position) {
    if(!texture) fetchTexture(renderer);
    SDL_RenderCopy(renderer,texture,nullptr, &position);
}

void Texture::fetchTexture(SDL_Renderer *renderer) {
    assert(!texture);
    auto loadedImage = IMG_Load(filePath.c_str());
    if(!loadedImage) throw std::runtime_error(std::string("Texture could not be loaded! ") + filePath);
    texture = SDL_CreateTextureFromSurface(renderer, loadedImage);
    if(!texture) throw std::runtime_error("Failed to create texture from surface!");
    SDL_FreeSurface(loadedImage);
}