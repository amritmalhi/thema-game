#ifndef PARALAX_H
/* ==========================================================================
   File: paralax.hpp
   ========================================================================== */
#define PARALAX_H

/**
 * @file paralax.hpp
 * @brief Contains the paralax background class
 */

#include <SFML/Graphics.hpp>

/// The paralax background object
class paralax
{
private:
    /// The shape for the paralax background
    sf::RectangleShape rectangles;

    /// The texture of the paralax background
    sf::Texture textures;

public:
    /**
     * @brief Creates a new paralax background object
     * @param fname Loads the given path as texture for the paralax
     */
    paralax(std::string fname = "../res/paralax.jpg");

    /**
     * @brief Updates the position of the paralax background given the players
     * coordinates
     * @param x The x position of the player
     * @param y The y position of the player
     */
    void update(float x, float y);

    /**
     * @brief Updates the texture of the paralax to a new texture
     * @param fname The path to the new texture
     */
    void update_texture(std::string fname);

    /**
     * @brief Draws the paralax background on the window
     * @param window The window to draw on
     */
    void draw(sf::RenderWindow& window);
};

#endif // PARALAX_H
