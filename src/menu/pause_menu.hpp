#ifndef PAUSE_MENU_H
/* ==========================================================================
   File: pause_menu.hpp
   ========================================================================== */
#define PAUSE_MENU_H

#include "menu.hpp"

enum {
    PAUSE_MENU_RESUME,
    PAUSE_MENU_BACK_TO_MAIN_MENU,
    PAUSE_MENU_QUIT_GAME
};

class pause_menu : public menu
{
public:
    pause_menu();

    void draw(sf::RenderWindow& window);
    void resize(int width, int height);
};

#endif // PAUSE_MENU_H
