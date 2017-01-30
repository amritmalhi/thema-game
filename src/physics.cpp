#include "physics.hpp"
#include <iostream>
/*///===============================================
  FILE:       physics.cpp
  AUTHOR:     Stefan de Beer
  DATE:       2017-01-20
/*///===============================================

#include "level_button.hpp"

physics::physics(sf::Vector2f position, sf::Vector2f size, object_type type):
collisionable(position, size, type),
previous_position(position)
{

}

bool physics::check_new_position(std::vector<collisionable*>& collisionables)
{
    for (auto& i : collisionables) {
        if (i != this) {
            if (detect_collision(*i)) {
				switch (i->get_object_type())
				{
				case object_level_button:
					((level_button*)i)->activate();
					break;
				}
                return true;
            }
        }
    }
    return false;
}

bool physics::detect_collision_position(collisionable & other, sf::Vector2f offset)
{
    sf::Vector2f buffer = position;
    position += offset;
    if(detect_collision(other)){
        position = buffer;
        return true;
    }
    position = buffer;
    return false;
}

object_position physics::detect_collision_direction(collisionable & other){
    if(detect_collision_position(other, sf::Vector2f(0, -1))){
        return ABOVE;
    }else if(detect_collision_position(other, sf::Vector2f(0, 1))){
        return UNDER;
    }else if(detect_collision_position(other, sf::Vector2f(-1, 0))){
        return LEFT;
    }else if(detect_collision_position(other, sf::Vector2f(1, 0))){
        return RIGHT;
    }
    return UNKNOWN;
}

