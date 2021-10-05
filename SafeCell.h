#ifndef AKNAKERESO_SAFECELL_H
#define AKNAKERESO_SAFECELL_H
#include "GridCell.h"
#include <array>
#include "Texture.h"

class SafeCell : public GridCell{
private:
    const uint8_t neighbourMines;
    static std::array<Texture, 9> textures;
public:
    explicit SafeCell(uint8_t neigbourMines);

    bool reveal() override;

    bool isMine() override;

    void render(SDL_Renderer *renderer, const SDL_Rect &renderPos) override;

    unsigned int getNeighbourMines() const override;

};


#endif //AKNAKERESO_SAFECELL_H
