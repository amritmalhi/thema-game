#ifndef MENU_MAIN_H
/* ==========================================================================
   File: menu_main.hpp
   ========================================================================== */
#define MENU_MAIN_H

#include "menu.hpp"

enum {
    NEW_GAME,
    QUIT_GAME
};

class menu_main : public menu
{
public:
    menu_main();

    void draw(sf::RenderWindow& window);
    void resize(int width, int height);
};

#endif // MENU_MAIN_H
