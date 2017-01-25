/* ==========================================================================
   File: pause_menu.cpp
   ========================================================================== */

#include "pause_menu.hpp"

pause_menu::pause_menu()
{
    add_button("Resume", PAUSE_MENU_RESUME);
    add_button("Main Menu", PAUSE_MENU_BACK_TO_MAIN_MENU);
    add_button("Quit Game", PAUSE_MENU_QUIT_GAME);
    center_buttons(1600, 900);
}

void pause_menu::draw(sf::RenderWindow& window)
{
    draw_buttons(window);
}

void pause_menu::resize(int width, int height)
{
    center_buttons(width, height);
}
