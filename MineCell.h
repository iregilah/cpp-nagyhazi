#ifndef AKNAKERESO_MINECELL_H
#define AKNAKERESO_MINECELL_H
#include "GridCell.h"
#include "Texture.h"

class MineCell : public GridCell {
private:
    static Texture revealedTexture;
public:
    bool reveal() override;

    bool isMine() override;

    void render(SDL_Renderer *renderer, const SDL_Rect &renderPos) override;

    unsigned int getNeighbourMines() const override;
};


#endif //AKNAKERESO_MINECELL_H
