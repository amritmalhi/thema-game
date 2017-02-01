/* ==========================================================================
   File: main_menu.cpp
   ========================================================================== */

#include "main_menu.hpp"

main_menu::main_menu()
{
    add_button("New Game", NEW_GAME);
    add_button("Credits", CREDITS);
    add_button("Quit Game", QUIT_GAME);
    center_buttons(1600, 900);
}

void main_menu::draw(sf::RenderWindow& window)
{
    draw_buttons(window);
}

void main_menu::resize(int width, int height)
{
    center_buttons(width, height);
}
