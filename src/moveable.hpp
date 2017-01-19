#ifndef MOVEABLE_HPP
#define MOVEABLE_HPP

#include <SFML/Graphics.hpp>

class moveable{
protected:
  sf::Vector2f speed;
  sf::Vector2f position;
public:
  moveable(sf::Vector2f speed, sf::Vector2f position);
  
  void set_speed(sf::Vector2f new_speed);
  void set_position(sf::Vector2f new_position);
  
  sf::Vector2f get_position();
  sf::Vector2f get_speed();

  void move(sf::Vector2f offset);
  void update();
};

#endif //MOVEABLE_HPP
