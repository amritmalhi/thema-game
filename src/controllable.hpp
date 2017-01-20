#ifndef CONTROLLABLE_HPP
#define CONTROLLABLE_HPP

#include "SFML/Window/Keyboard.hpp"

class controllable{
private:
  sf::Keyboard::Key move_left_key;
  sf::Keyboard::Key move_right_key;
  sf::Keyboard::Key move_up_key;
  
public:
  controllable(sf::Keyboard::Key move_left_key = sf::Keyboard::Left,
               sf::Keyboard::Key move_right_key = sf::Keyboard::Right,
			   sf::Keyboard::Key move_up_key = sf::Keyboard::Up);
  void handle_input();
  virtual void move_left(){}
  virtual void move_right(){}
  virtual void move_up(){}
};

#endif //CONTROLLABLE_HPP
