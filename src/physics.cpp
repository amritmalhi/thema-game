#include "physics.hpp"
#include <iostream>
/*///===============================================
  FILE:       physics.cpp
  AUTHOR:     Stefan de Beer
  DATE:       2017-01-20
/*///===============================================

physics::physics(sf::Vector2f position, sf::Vector2f size) :
    collisionable(position, size),
    moveable(),
    previous_position(position)
{}

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

void physics::handle_collision(collisionable & other){
    object_position pos = detect_position(other);
    //std::cout<<pos<<std::endl;
    if(pos == UNDER){
        speed.y = 0;
        position.y = previous_position.y;
    }
    else if(pos == ABOVE){
        speed.y = 0;
        position.y = previous_position.y;
    }
    else if (pos == LEFT) {
        speed.x = 0;
        position.x = previous_position.x;
    }
    else if (pos == RIGHT) {
        speed.x = 0;
        position.x = previous_position.x;
    }


}
