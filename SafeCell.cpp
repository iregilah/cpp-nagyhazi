#include "SafeCell.h"
#include "Defines.h"


SafeCell::SafeCell(uint8_t neigbourMines) : neighbourMines(neigbourMines) {}

bool SafeCell::reveal() {
    if(marked) return false;
    revealed = true;
    return false;
}

bool SafeCell::isMine() {
    return false;
}

void SafeCell::render(SDL_Renderer *renderer, const SDL_Rect &renderPos) {
    if(marked){
        markedTexture.render(renderer, renderPos);
        return;
    }
    if(revealed){
        textures[neighbourMines].render(renderer, renderPos);
        return;
    }
    hiddenTexture.render(renderer, renderPos);
}

std::array<Texture, 9> SafeCell::textures = {
        Texture(Defines::TexturePaths::Cells::REV_0),
        Texture(Defines::TexturePaths::Cells::REV_1),
        Texture(Defines::TexturePaths::Cells::REV_2),
        Texture(Defines::TexturePaths::Cells::REV_3),
        Texture(Defines::TexturePaths::Cells::REV_4),
        Texture(Defines::TexturePaths::Cells::REV_5),
        Texture(Defines::TexturePaths::Cells::REV_6),
        Texture(Defines::TexturePaths::Cells::REV_7),
        Texture(Defines::TexturePaths::Cells::REV_8)
};

unsigned int SafeCell::getNeighbourMines() const {
    return neighbourMines;
}
