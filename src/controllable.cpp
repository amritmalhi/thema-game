#include "controllable.hpp"
#include <math.h>

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

    if( sf::Joystick::isConnected( 0 ) ) {
	    // what's the current position of the X and Y axes of joystick number 0?
	    float joystick_x_axis = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
        float normalised_j_x_axis = fabs(joystick_x_axis / 100);

	    if (joystick_x_axis < -15) {
            move_left(collisionables, normalised_j_x_axis);
        }
        else if (joystick_x_axis > 15) {
            move_right(collisionables, normalised_j_x_axis);
        }
        if (sf::Joystick::isButtonPressed(0, 1) ) {
            move_up(collisionables);
        }
    }
	
}
