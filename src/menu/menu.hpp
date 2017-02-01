#ifndef MENU_H
/* ==========================================================================
   File: menu.hpp
   ========================================================================== */
#define MENU_H

/**
 * @file menu.hpp
 * @brief The super class for menus
 */

#include <SFML/Graphics.hpp>

#include <vector>

#include "menu_button.hpp"

/// The super class that all menu's are childs of
class menu
{
private:
    /// The list of buttons the menu has
    std::vector<menu_button> buttons;

    /// The currently selected button for keyboard / controller support in menus
    int selected_button = -1;

protected:
    /**
     * @brief Adds a button to the menu
     * @param name The text written on the button
     * @param ret The number the button returns when activated
     * @param position The location the button is placed at
     */
    void add_button(std::string name,
                    int ret,
                    sf::Vector2f position = sf::Vector2f(0, 0));

    /**
     * @brief Draws the button on the window
     * @param window The window that the buttons get drawn on
     */
    void draw_buttons(sf::RenderWindow& window);

    /**
     * @brief Centers the buttons in the center of the screen
     * @param width The width of the screen
     * @param height The height of the screen
     * @param gap The gap in pixels between the buttons
     */
    void center_buttons(int width, int height, int gap = 10);

public:
    /**
     * @brief Handles mouse clicks in the menu
     * @param x The x coordinate of the mouse
     * @param y The y coordinate of the mouse
     * @return Returns -1 if no button was clicked or the ret value of the
     * Button if one was clicked
     */
    int handle_mouse_input(int x, int y);

    /**
     * @brief Updates the mouse position for highlighting of buttons if the
     * mouse is over them
     * @param x The x coordinate of the mouse
     * @param y The y coordinate of the mouse
     */
    void update_mouse_position(int x, int y);

    /**
     * @brief Selects the next button as currently selected for keyboard /
     * controller input
     */
    void handle_button_input_next();

    /**
     * @brief Selects the previous button as currently selected for keyboard /
     * controller input
     */
    void handle_button_input_previous();

    /**
     * @brief Executes the currently selected button for keyboard / controller
     * input
     * @return Returns -1 if no button was clicked or the ret value of the
     * Button if one was clicked
     */
    int handle_button_input_execute();

    /**
     * @brief Draws the menu on the window
     * @param window The window to draw on
     */
    virtual void draw(sf::RenderWindow& window) = 0;

    /**
     * @brief Handles new positions when the window gets resized
     * @param width The new width of the window
     * @param height The new height of the window
     */
    virtual void resize(int width, int height) = 0;
};

#endif // MENU_H
