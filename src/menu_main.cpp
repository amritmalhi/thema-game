/* ==========================================================================
   File: menu_main.cpp
   ========================================================================== */

#include "menu_main.hpp"

#include <iostream>

menu_main::menu_main()
{
    add_button("New Game", NEW_GAME);
    add_button("Quit Game", QUIT_GAME);
    center_buttons(1600, 900);
}

void menu_main::draw(sf::RenderWindow& window)
{
    draw_buttons(window);
}

void menu_main::resize(int width, int height)
{
    center_buttons(width, height);
}
