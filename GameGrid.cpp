#include "GameGrid.h"

#include "MineCell.h"
#include "SafeCell.h"
#include "Defines.h"

#include <random>
#include <ctime>
#include <algorithm>
#include <cassert>
#include <exception>
#include <stdexcept>

GameGrid::GameGrid(const unsigned width, const unsigned height, const unsigned mineCount) : gameGrid(width * height),
                                                                                            width(width),
                                                                                            height(height) {

    std::vector<bool> mineGrid(width * height, false);
    for (unsigned i = 0; i < std::min<size_t>(mineGrid.size(), mineCount); ++i) {
        mineGrid[i] = true;
    }

    // https://en.cppreference.com/w/cpp/algorithm/random_shuffle
    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(mineGrid.begin(), mineGrid.end(), g);

    for (unsigned x = 0; x < width; ++x) {
        for (unsigned y = 0; y < height; ++y) {
            if (getNeighbourMine(mineGrid, x, y)) {
                getGridElement(x, y) = std::make_unique<MineCell>();
            } else {
                getGridElement(x, y) = std::make_unique<SafeCell>(scanNeighbourMines(mineGrid, x, y));
            }
        }
    }

}

//gamegrid: objektumokat tartalmaz (gridcell)
//minegrid: csak bool elemeket tartalmaz (van akna/nincs akna)

std::unique_ptr<GridCell> &GameGrid::getGridElement(const unsigned x, const unsigned y) {
    if (!(x < width && y < height))
        throw std::out_of_range("Grid index out of range");

    return gameGrid[x + y * width];
}

const std::unique_ptr<GridCell> &GameGrid::getGridElement(const unsigned x, const unsigned y) const {
    if (!(x < width && y < height))
        throw std::out_of_range("Grid index out of range");

    return gameGrid[x + y * width];
}

bool GameGrid::getNeighbourMine(const std::vector<bool> &mineGrid, const int x, const int y) const {
    if (x < 0 || x >= width || y < 0 || y >= height) return false;
    return mineGrid[x + y * width];
}

unsigned GameGrid::scanNeighbourMines(const std::vector<bool> &mineGrid, const int x, const int y) const {
    return   getNeighbourMine(mineGrid, x - 1, y - 1) + getNeighbourMine(mineGrid, x, y - 1) + getNeighbourMine(mineGrid, x + 1, y - 1)
           + getNeighbourMine(mineGrid, x - 1, y)                    /*cella*/                  + getNeighbourMine(mineGrid, x + 1, y)
           + getNeighbourMine(mineGrid, x - 1, y + 1) + getNeighbourMine(mineGrid, x, y + 1) + getNeighbourMine(mineGrid, x + 1, y + 1);

}

// Az összes cellának meghívja a renderét a megfelelő cellrect-tel (téglalappal)
//hova renderelje az egész játékmezőt
void GameGrid::render(SDL_Renderer *renderer, const SDL_Rect &destRect) const {
    //TODO: ne legyen kerekítve
    const int cellWidth = static_cast<int>(destRect.w / width);
    const int cellHeight = static_cast<int>(destRect.h / height);
    SDL_Rect cellRect = {};
    cellRect.w = cellWidth;
    cellRect.h = cellHeight;

    // Ez rja ki az egész táblát
    for (int x = 0; x < width; ++x) {
        cellRect.x = x * cellWidth;
        for (int y = 0; y < height; ++y) {
            cellRect.y = y * cellHeight;
            getGridElement(x, y)->render(renderer, cellRect);
        }
    }
}

//A cellára kattintást kezeli
bool GameGrid::click(const SDL_Rect &destRect, const SDL_Event &clickEvent) {

    //pozíciót korrigáljuk
    const unsigned posX = clickEvent.button.x - destRect.x;
    const unsigned posY = clickEvent.button.y - destRect.y;

    //kiszámoljuk a szélességét, és magasságát a celláknak
    const unsigned cellWidth = destRect.w / width;
    const unsigned cellHeight = destRect.h / height;

    //kiszámoljuk melyik indexű cellára kattintottunk.
    const unsigned cellX = posX / cellWidth;
    const unsigned cellY = posY / cellHeight;

    switch (clickEvent.button.button) {
        case SDL_BUTTON_LEFT:
            if(revealGridElements(cellX, cellY))
                return true;
            // Check for victory
            for(const auto& cell : gameGrid){
                if(!cell->isRevealed() && !cell->isMine()) return false;
            }
            return true; // Game over
            break;
        case SDL_BUTTON_RIGHT:
            getGridElement(cellX, cellY)->mark();
            return false; // Nem robbantunk fel
            break;
    }
}

void GameGrid::revealAll() {
    for (auto &cell : gameGrid) cell->reveal();
}

bool GameGrid::revealGridElements(unsigned int x, unsigned int y) {
    if (x < 0 || x >= width || y < 0 || y >= height) return false;
    if (getGridElement(x, y)->isRevealed()) return false;
    bool result = getGridElement(x, y)->reveal();
    if (getGridElement(x, y)->getNeighbourMines() == 0) {
        revealGridElements(x - 1, y - 1);
        revealGridElements(x, y - 1);
        revealGridElements(x + 1, y - 1);
        revealGridElements(x - 1, y);
        revealGridElements(x + 1, y);
        revealGridElements(x - 1, y + 1);
        revealGridElements(x, y + 1);
        revealGridElements(x + 1, y + 1);
    }
    return result;
}
