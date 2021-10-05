#ifndef AKNAKERESO_GRIDCELL_H
#define AKNAKERESO_GRIDCELL_H
#include <SDL2/SDL.h>
#include "Texture.h"

class GridCell {
protected:
    bool marked = false;
    bool revealed = false;
    static Texture hiddenTexture;
    static Texture markedTexture;
public:

    // Returns true if the cell exploded
    virtual bool reveal() = 0;

    virtual bool isMine() = 0;
    bool isMarked() const;

    void mark();

    virtual void render(SDL_Renderer *renderer, const SDL_Rect &renderPos) = 0;
    virtual unsigned getNeighbourMines() const = 0;

    bool isRevealed() const;
};


#endif //AKNAKERESO_GRIDCELL_H
