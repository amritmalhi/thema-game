/* ==========================================================================
   File: paralax.cpp
   ========================================================================== */

#include "paralax.hpp"

#include "defines.hpp"

paralax::paralax(std::string fname)
{
    rectangles.setSize(sf::Vector2f(3840, 2160));

    textures.loadFromFile(fname);
    rectangles.setTexture(&textures);
}

void paralax::update(float x, float y)
{
    rectangles.setPosition(sf::Vector2f(x / 3.0f, (y / 1.3f) - 580));
}

void paralax::update_texture(std::string fname)
{
    textures.loadFromFile(fname);
    rectangles.setTexture(&textures);
}

void paralax::draw(sf::RenderWindow& window)
{
    window.draw(rectangles);
}
