#ifndef MAIN_MENU_H
/* ==========================================================================
   File: main_menu.hpp
   ========================================================================== */
#define MAIN_MENU_H

#include "menu.hpp"

enum {
    NEW_GAME,
    QUIT_GAME
};

class main_menu : public menu
{
public:
    main_menu();

    void draw(sf::RenderWindow& window);
    void resize(int width, int height);
};

#endif // MAIN_MENU_H
