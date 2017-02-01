#ifndef PAUSE_MENU_H
/* ==========================================================================
   File: pause_menu.hpp
   ========================================================================== */
#define PAUSE_MENU_H

/**
 * @file pause_menu.hpp
 * @brief The pause menu class
 */

#include "menu.hpp"

/// The list of different button return values from the pause menu
enum {
    PAUSE_MENU_RESUME,
    PAUSE_MENU_BACK_TO_MAIN_MENU,
    PAUSE_MENU_QUIT_GAME
};

/// The pause menu class
class pause_menu : public menu
{
public:
    /**
     * @brief Creates a new pause menu object
     */
    pause_menu();

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

#endif // PAUSE_MENU_H
