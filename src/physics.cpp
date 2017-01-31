#include "physics.hpp"
#include <iostream>
/*///===============================================
  FILE:       physics.cpp
  AUTHOR:     Stefan de Beer
  DATE:       2017-01-20
/*///===============================================

#include "level_button.hpp"
#include <array>
#include <memory>

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


bool physics::detect_collision_position(std::vector<collisionable*>& collisionables, sf::Vector2f offset)
{
    sf::Vector2f buffer = position;
    position += offset;
    for(auto& i : collisionables){
        if(i!=this){
            if(detect_collision(*i)){
                position = buffer;
                return true;
            }
        }
        
    }
    position = buffer;
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

collision_direction physics::detect_collision_direction(std::vector<collisionable*>& collisionables, sf::Vector2f offset){
    collision_direction buffer;
    if(detect_collision_position(collisionables, sf::Vector2f(0, -offset.y))){
        buffer.above = true;
    }if(detect_collision_position(collisionables, sf::Vector2f(0, offset.y))){
        buffer.under = true;
    }if(detect_collision_position(collisionables, sf::Vector2f(-offset.x, 0))){
        buffer.left = true;
    }if(detect_collision_position(collisionables, sf::Vector2f(offset.x, 0))){
        buffer.right = true;
    }
    return buffer;
}


collision_direction physics::detect_collision_direction(collisionable & other, sf::Vector2f offset){
    collision_direction buffer;
    if(detect_collision_position(other, sf::Vector2f(0, -offset.y))){
        buffer.above = true;
    }if(detect_collision_position(other, sf::Vector2f(0, offset.y))){
        buffer.under = true;
    }if(detect_collision_position(other, sf::Vector2f(-offset.x, 0))){
        buffer.left = true;
    }if(detect_collision_position(other, sf::Vector2f(offset.x, 0))){
        buffer.right = true;
    }
    return buffer;
}

