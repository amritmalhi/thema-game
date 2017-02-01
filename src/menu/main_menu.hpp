#ifndef MAIN_MENU_H
/* ==========================================================================
   File: main_menu.hpp
   ========================================================================== */
#define MAIN_MENU_H

/**
 * @file main_menu.hpp
 * @brief The main menu class
 */

#include "menu.hpp"

/// The list of different button return values from the main menu
enum {
    NEW_GAME,
    CREDITS,
    QUIT_GAME
};

/// The main menu class
class main_menu : public menu
{
public:
    /**
     * @brief Creates a new main menu object
     */
    main_menu();

    /**
     * @brief Draws the menu on the window
     * @param window The window to draw on
     */
    void draw(sf::RenderWindow& window);

    /**
     * @brief Handles new positions when the window gets resized
     * @param width The new width of the window
     * @param height The new height of the window
     */
    void resize(int width, int height);
};

#endif // MAIN_MENU_H
