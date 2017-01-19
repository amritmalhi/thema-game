#ifndef CONTROLLABLE_HPP
#define CONTROLLABLE_HPP

#include "SFML/Window/Keyboard.hpp"

class controllable{
private:
  sf::Keyboard::Key move_left_key;
  sf::Keyboard::Key move_right_key;
  
public:
  controllable(sf::Keyboard::Key move_left_key = sf::Keyboard::Left,
               sf::Keyboard::Key move_right_key = sf::Keyboard::Right);
  void handle_input();
  virtual void move_left(){}
  virtual void move_right(){}
};

#endif //CONTROLLABLE_HPP
