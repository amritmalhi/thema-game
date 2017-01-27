#include "physics.hpp"
#include <iostream>
/*///===============================================
  FILE:       physics.cpp
  AUTHOR:     Stefan de Beer
  DATE:       2017-01-20
/*///===============================================

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
                return true;
            }
        }
    }
    return false;
}


object_position physics::detect_collision_position(std::vector<collisionable*>& collisionables,
                                                   sf::Vector2f offset)
{
    
}
