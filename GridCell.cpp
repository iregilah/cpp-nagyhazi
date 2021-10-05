#include "GridCell.h"
#include "Defines.h"

bool GridCell::isMarked() const {
    return marked;
}

void GridCell::mark() {
    if(revealed) return;
    marked = !marked;
}

Texture GridCell::hiddenTexture{Defines::TexturePaths::Cells::HIDDEN};
Texture GridCell::markedTexture{Defines::TexturePaths::Cells::FLAG};

bool GridCell::isRevealed() const {
    return revealed;
}
