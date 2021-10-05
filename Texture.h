#ifndef AKNAKERESO_TEXTURE_H
#define AKNAKERESO_TEXTURE_H
#include <string>
#include <memory>
#include "SDL2/SDL.h"

class Texture {
private:
    std::string filePath;
    SDL_Texture *texture = nullptr;
    void fetchTexture(SDL_Renderer* renderer);

public:
    explicit Texture(std::string filePath);
    Texture(const Texture&) = delete;
    void operator=(const Texture&) = delete;
    void render(SDL_Renderer* renderer, const SDL_Rect& position);

    ~Texture();
};


#endif //AKNAKERESO_TEXTURE_H
