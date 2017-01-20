#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <SFML/Graphics.hpp>
#include "moveable.hpp"
#include "drawable.hpp"
#include "object.hpp"

class rectangle : public drawable, public object
{
public:
    rectangle(sf::Vector2f position,
              sf::Vector2f size,
              sf::Color color = sf::Color::Red);
    void draw(sf::RenderWindow & window) override;
};

#endif //RECTANGLE_HPP
