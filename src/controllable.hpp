#ifndef CONTROLLABLE_HPP
#define CONTROLLABLE_HPP

#include "SFML/Window/Keyboard.hpp"

#include "collisionable.hpp"
#include <list>

///The class that handles the input and is for controlling objects.
class controllable{
private:
  sf::Keyboard::Key move_left_key;
  sf::Keyboard::Key move_right_key;
  sf::Keyboard::Key move_up_key;

public:
    ///The constructor. Takes three sf::keyboard keys for moving left, right and up
    ///These are by default set to sf::Keyboard::Left, sf::Keyboard::Right and sf::Keyboard::Up.
  controllable(sf::Keyboard::Key move_left_key = sf::Keyboard::Left,
               sf::Keyboard::Key move_right_key = sf::Keyboard::Right,
			   sf::Keyboard::Key move_up_key = sf::Keyboard::Up);
  ///This function handles the keyboard input.
  void handle_input(std::vector<collisionable*>& collisionables);
  ///Virtual function for moving left. Does nothing by default.
  ///Takes an int speed_modifier with default value of 1 for controller support.
  virtual void move_left(float speed_modifier = 1){}
    
  ///Virtual function for moving right. Does nothing by default.
  ///Takes an int speed_modifier with default value of 1 for controller support.
  virtual void move_right(float speed_modifier = 1){}
    
  ///Virtual function for moving up(used for jumping). Does nothing by default.
  ///Takes a std::vector of collisionable pointer for collision detection.
  virtual void move_up(std::vector<collisionable*>& collisionables){}
};

#endif //CONTROLLABLE_HPP
