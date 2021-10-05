cmake_minimum_required(VERSION 3.19)
project(Aknakereso)

set(CMAKE_CXX_STANDARD 17)

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} main.cpp GridCell.cpp MineCell.cpp SafeCell.cpp GameGrid.cpp InGameState.cpp InGameState.h Button.cpp Button.h NewGameButton.cpp NewGameButton.h MainMenuButton.cpp MainMenuButton.h ExitButton.cpp ExitButton.h GameStateHandler.cpp GameStateHandler.h MainMenuState.cpp MainMenuState.h Defines.h NewGameState.cpp NewGameState.h ScrollBox.cpp ScrollBox.h NextButton.cpp NextButton.h Texture.cpp Texture.h)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})