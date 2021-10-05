#ifndef AKNAKERESO_DEFINES_H
#define AKNAKERESO_DEFINES_H
#include <string>
#include <array>
namespace Defines{
    inline const unsigned WINDOW_WIDTH = 1280;
    inline const unsigned WINDOW_HEIGHT = 720;

    inline const unsigned MINE_SHUFFLE = 1000;

    inline const SDL_Color BACKGROUND_COLOUR = {0x7F,0x7F,0x7F,0xFF};

    namespace TexturePaths{
        inline const std::string PREFIX = "textures/";
        namespace Buttons{
            inline const std::string EXIT = PREFIX + "btn_exit.png";
            inline const std::string NEXT = PREFIX + "btn_next.png";
            inline const std::string MENU = PREFIX + "btn_menu.png";
            inline const std::string NEW_GAME = PREFIX + "btn_newgame.png";
        }
        namespace Cells{
            inline const std::string HIDDEN = PREFIX + "cell_hidden.png";
            inline const std::string REV_0 = PREFIX + "cell_rev0.png";
            inline const std::string REV_1 = PREFIX + "cell_rev1.png";
            inline const std::string REV_2 = PREFIX + "cell_rev2.png";
            inline const std::string REV_3 = PREFIX + "cell_rev3.png";
            inline const std::string REV_4 = PREFIX + "cell_rev4.png";
            inline const std::string REV_5 = PREFIX + "cell_rev5.png";
            inline const std::string REV_6 = PREFIX + "cell_rev6.png";
            inline const std::string REV_7 = PREFIX + "cell_rev7.png";
            inline const std::string REV_8 = PREFIX + "cell_rev8.png";
            inline const std::string MINE = PREFIX + "cell_mine.png";
            inline const std::string FLAG = PREFIX + "cell_flag.png";
        }
        namespace Scroller{
            inline const std::string INCREMENT = PREFIX + "scrll_inc.png";
            inline const std::string DECREMENT = PREFIX + "scrll_dec.png";
            inline const SDL_Color BORDER_COLOUR = {0xFF, 0x00, 0x00, 0xFF};
        }
        inline const unsigned NUMBER_WIDTH = 20;
        inline const unsigned NUMBER_HEIGHT = NUMBER_WIDTH * 2;
        inline const std::array<std::string,10> NUMBERS = {
                PREFIX+"num_0.png",
                PREFIX+"num_1.png",
                PREFIX+"num_2.png",
                PREFIX+"num_3.png",
                PREFIX+"num_4.png",
                PREFIX+"num_5.png",
                PREFIX+"num_6.png",
                PREFIX+"num_7.png",
                PREFIX+"num_8.png",
                PREFIX+"num_9.png"
        };
        inline const std::string LOGO = PREFIX + "logo.png";
        inline const unsigned LOGO_H = 200;
        inline const unsigned LOGO_W = LOGO_H*4;

    }
}
#endif //AKNAKERESO_DEFINES_H
