#include "controllable.hpp"

controllable::controllable(sf::Keyboard::Key move_left_key,
                           sf::Keyboard::Key move_right_key,
						   sf::Keyboard::Key move_up_key):
  move_left_key(move_left_key),
  move_right_key(move_right_key),
  move_up_key(move_up_key)
{}

void controllable::handle_input(std::vector<collisionable*>& collisionables){
	if(sf::Keyboard::isKeyPressed(move_left_key)){
		move_left(collisionables);
	}
	if(sf::Keyboard::isKeyPressed(move_right_key)){
		move_right(collisionables);
	}
	if (sf::Keyboard::isKeyPressed(move_up_key)) {
		move_up(collisionables);
	}
}
