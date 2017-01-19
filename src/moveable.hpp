#ifndef MOVEABLE_HPP
#define MOVEABLE_HPP

#include <SFML/Graphics.hpp>

class moveable{
protected:
  sf::Vector2f speed;
public:
  moveable(sf::Vector2f speed);
  virtual void update()=0;
  virtual void move(sf::Vector2f offset){}
};

#endif //MOVEABLE_HPP
