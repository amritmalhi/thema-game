#ifndef CREDITS_H
/* ==========================================================================
   File: credits.hpp
   ========================================================================== */
#define CREDITS_H

/**
 * @file credits.hpp
 * @brief Contains the credits screen
 */

#include "menu.hpp"

#include <vector>

/// The credits screen
class credits : public menu
{
private:
    /// The list of credits that need to be shown
    std::vector<sf::Text> credit_text;

    /// The height of the window
    int window_height;

public:
    /**
     * @brief Creates a new credits screen object
     */
    credits();

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

    /**
     * @brief Check wether the credits finished displaying
     * @return Returns true if the credits finished displaying and false
     * otherwise
     */
    bool credits_finished();
};

#endif // CREDITS_H
