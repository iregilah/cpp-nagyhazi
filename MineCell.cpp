#include "MineCell.h"
#include "Defines.h"

bool MineCell::reveal() {
    if(marked) return false;
    revealed = true;
    return true;
}

bool MineCell::isMine() {
    return true;
}

void MineCell::render(SDL_Renderer *renderer, const SDL_Rect &renderPos) {
    if(marked){
        markedTexture.render(renderer, renderPos);
        return;
    }
    if(revealed){
        revealedTexture.render(renderer, renderPos);
        return;
    }
    hiddenTexture.render(renderer, renderPos);
}

Texture MineCell::revealedTexture{Defines::TexturePaths::Cells::MINE};

unsigned int MineCell::getNeighbourMines() const {
    return 9; // Spec. érték
}
