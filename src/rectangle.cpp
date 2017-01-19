#include "rectangle.hpp"

rectangle::rectangle(sf::Vector2f pos, sf::Vector2f size):
  drawable(position),
  size(size)
{}

void rectangle::draw(sf::RenderWindow & window){
  sf::RectangleShape myRect;
  myRect.setSize(size);
  myRect.setPosition(position);
  window.draw(myRect);
}
