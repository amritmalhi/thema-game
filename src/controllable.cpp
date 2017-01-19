#include "controllable.hpp"

controllable::controllable(sf::Keyboard::Key move_left_key,
                           sf::Keyboard::Key move_right_key):
  move_left_key(move_left_key),
  move_right_key(move_right_key)
{}

void controllable::handle_input(){
  if(sf::Keyboard::isKeyPressed(move_left_key)){
    move_left();
  }
  if(sf::Keyboard::isKeyPressed(move_right_key)){
    move_right();
  }
}
