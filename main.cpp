#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "GameStateHandler.h"
#include "Defines.h"

#include <iostream>
#include <exception>
#include <stdexcept>

const unsigned gridSize = 5;

int main(int argc, char* argv[]) {
    SDL_Window *window = nullptr;
    SDL_Renderer *windowRenderer = nullptr;

    try {
        if(SDL_Init(SDL_INIT_VIDEO) ){
            std::cerr << "Nem sikerült inicializálni az SDL programkönyvtárat! Hibaüzenet: " << SDL_GetError() << std::endl;
            throw std::runtime_error("Unable to intialize SDL");
        }

        window = SDL_CreateWindow("Aknakereső", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Defines::WINDOW_WIDTH,
                                              Defines::WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
        if (!window) {
            std::cerr << "Nem sikerült létrehozni az ablakot! Hibaüzenet: " << SDL_GetError() << std::endl;
            throw std::runtime_error("Unable to intialize SDL Window");
        }

        windowRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

        if (!windowRenderer) {
            std::cerr << "Nem sikerült létrehozni a renderert! Hibaüzenet: " << SDL_GetError() << std::endl;
            throw std::runtime_error("Unable to intialize SDL Renderer");
        }

        if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
            std::cerr << "Nem sikerült inicializálni az SDL_image modult! Hibaüzenet: " << IMG_GetError() << std::endl;
            throw std::runtime_error("Unable to intialize SDL Image");
        }
    }
    catch (std::runtime_error& e) {
        SDL_DestroyRenderer(windowRenderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        std::cerr << "Failed to initialize SDL program will terminate :(";
        exit(1);
    }


    bool shouldKeepRunning = true;
    while(shouldKeepRunning){
        SDL_Event event;
        while(SDL_PollEvent(&event)){
            switch (event.type) {
                case SDL_MOUSEBUTTONUP:
                    GameStateHandler::getInstance().click(event);
                    break;
                case SDL_QUIT:
                    shouldKeepRunning = false;
                    break;
            }
        }

        //képkifeketítés
        SDL_SetRenderDrawColor(windowRenderer, Defines::BACKGROUND_COLOUR.r, Defines::BACKGROUND_COLOUR.g, Defines::BACKGROUND_COLOUR.b, Defines::BACKGROUND_COLOUR.a);
        SDL_RenderClear(windowRenderer);

        GameStateHandler::getInstance().render(windowRenderer);

        //Ezzel jelenenítjük meg a képet.
        SDL_RenderPresent(windowRenderer);
    }
    //Ezzel lépünk ki az SDL-ből. Hogy feltakaríthassunk magunk után.
    SDL_DestroyRenderer(windowRenderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();


    return 0;
}
