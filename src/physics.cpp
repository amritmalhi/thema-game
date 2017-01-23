#include "physics.hpp"
#include <iostream>
/*///===============================================
  FILE:       physics.cpp
  AUTHOR:     Stefan de Beer
  DATE:       2017-01-20
/*///===============================================

physics::physics(sf::Vector2f position, sf::Vector2f size):
    collisionable(position, size),
    previous_position(position)
{}

void physics::handle_collision(collisionable & other){
    object_position pos = detect_position(other);
    //std::cout<<pos<<std::endl;
    if(pos == UNDER){
        fall_speed = 0;
        position.y = previous_position.y;
    }
    else if(pos == ABOVE){
        fall_speed = 0;
        position.y = previous_position.y;
    }

    
}
