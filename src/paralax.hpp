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
    paralax(std::string fname = "../res/paralax.jpg");

    void update(float x, float y);
    void update_texture(std::string fname);
    void draw(sf::RenderWindow& window);
};

#endif // PARALAX_H
