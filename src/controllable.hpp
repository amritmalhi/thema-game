#ifndef CONTROLLABLE_HPP
#define CONTROLLABLE_HPP

#include "SFML/Window/Keyboard.hpp"

#include "collisionable.hpp"
#include <list>

class controllable{
private:
  sf::Keyboard::Key move_left_key;
  sf::Keyboard::Key move_right_key;
  sf::Keyboard::Key move_up_key;

public:
  controllable(sf::Keyboard::Key move_left_key = sf::Keyboard::Left,
               sf::Keyboard::Key move_right_key = sf::Keyboard::Right,
			   sf::Keyboard::Key move_up_key = sf::Keyboard::Up);
  void handle_input(std::vector<collisionable*>& collisionables);
  virtual void move_left(std::vector<collisionable*>& collisionables, float acceleration_modifier = 1){}
  virtual void move_right(std::vector<collisionable*>& collisionables, float acceleration_modifier = 1){}
  virtual void move_up(std::vector<collisionable*>& collisionables){}
};

#endif //CONTROLLABLE_HPP
