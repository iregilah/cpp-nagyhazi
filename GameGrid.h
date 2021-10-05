#ifndef AKNAKERESO_GAMEGRID_H
#define AKNAKERESO_GAMEGRID_H
#include "GridCell.h"
#include <vector>
#include <memory>

class GameGrid {
public:
    GameGrid(unsigned width, unsigned height, unsigned mineCount);

    bool click(const SDL_Rect& destRect, const SDL_Event& clickEvent);

    void render(SDL_Renderer* renderer, const SDL_Rect& destRect) const;

    void revealAll();
private:
    std::vector<std::unique_ptr<GridCell>> gameGrid;
    const unsigned width, height;

    std::unique_ptr<GridCell>& getGridElement(unsigned x, unsigned y);
    const std::unique_ptr<GridCell>& getGridElement(unsigned x, unsigned y) const;
    unsigned scanNeighbourMines(const std::vector<bool>& mineGrid, int x, int y) const;
    bool getNeighbourMine(const std::vector<bool>& mineGrid, int x, int y) const;

    bool revealGridElements(unsigned x, unsigned y);
};


#endif //AKNAKERESO_GAMEGRID_H
