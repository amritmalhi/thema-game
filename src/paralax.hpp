#ifndef PARALAX_H
/* ==========================================================================
   File: paralax.hpp
   ========================================================================== */
#define PARALAX_H

#include <SFML/Graphics.hpp>

class paralax
{
private:
    sf::RectangleShape rectangles;
    sf::Texture textures;

public:
    paralax();

    void update(float x, float y);
    void draw(sf::RenderWindow& window);
};

#endif // PARALAX_H
