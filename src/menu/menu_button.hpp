#ifndef MENU_BUTTON_H
/* ==========================================================================
   File: menu_button.hpp
   ========================================================================== */
#define MENU_BUTTON_H

/**
 * @file menu_button.hpp
 * @brief Contains the button class for menus
 */

#include <SFML/Graphics.hpp>

#include <string>

/// The button class that is used in menu's
class menu_button
{
private:
    /// The value to return if clicked
    int ret;

    /// The size of the button
    sf::Vector2f size;

    /// The text on the button
    sf::Text text;

    /// The shape of the button
    sf::RectangleShape background;

public:
    /**
     * @brief Creates a new menu button object
     * @param name The text on the button
     * @param ret The value to return if the button is clicked
     * @param position The position of the button
     * @param size The size of the button
     */
    menu_button(std::string name,
                int ret,
                sf::Vector2f position = sf::Vector2f(0, 0),
                sf::Vector2f size = sf::Vector2f(500, 70));

    /**
     * @brief Check wether the given location is inside the button
     * @param x The x location to check
     * @param y The y location to check
     * @return Returns true if the location is inside the button, false
     * otherwise
     */
    bool check_location(int x, int y);

    /**
     * @brief Changes the buttons appearens if it is currently selected or
     * highlighted
     * @param active If true is passed the button will be highlighted
     */
    void set_active(bool active);

    /**
     * @brief Draws the button on the window
     * @param window The window to draw on
     */
    virtual void draw(sf::RenderWindow& window);

    /**
     * @brief Sets the buttons position to a new position
     * @param position The new position of the button
     */
    virtual void set_position(sf::Vector2f position);

    /**
     * @brief Gets the return value of the button
     * @return The value set to return if the button is pressed
     */
    inline int get_return() const {return ret;}

    /**
     * @brief Gets the width of the button
     * @return The width of the button
     */
    inline float get_width() const {return size.x;}

    /**
     * @brief Gets the height of the button
     * @return The height of the button
     */
    inline float get_height() const {return size.y;}
};

#endif // MENU_BUTTON_H
