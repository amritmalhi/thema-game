#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <SFML/Graphics.hpp>
#include "moveable.hpp"
#include "drawable.hpp"

class rectangle : public drawable{
private:
  sf::Vector2f size;
public:
  rectangle(sf::Vector2f pos, sf::Vector2f size);
  void draw(sf::RenderWindow & window) override;
};

#endif //RECTANGLE_HPP
