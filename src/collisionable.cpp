#include "collisionable.hpp"
/*///===============================================
  FILE:       collisionable.cpp
  AUTHOR:     Stefan de Beer
  DATE:       2017-01-20
/*///===============================================

collisionable::collisionable(sf::Vector2f position, sf::Vector2f size):
    object(position, size)
{}


bool collisionable::detect_collision(collisionable & other){
    sf::IntRect this_box((int)position.x, (int)position.y, (int)size.x, (int)size.y);
    sf::IntRect other_box((int)other.position.x,
                          (int)other.position.y,
                          (int)other.size.x,
                          (int)other.size.y);
    return (this_box.intersects(other_box));
}


object_position collisionable::detect_position(collisionable & other){
    sf::IntRect this_box((int)position.x, (int)position.y, (int)size.x, (int)size.y);
    sf::IntRect other_box((int)other.position.x,
                          (int)other.position.y,
                          (int)other.size.x,
                          (int)other.size.y);
    if(this_box.top > other_box.top){
        return ABOVE;
    }
    if(this_box.left>other_box.left && this_box.top+this_box.height>other_box.top){
        return LEFT;
    }
    if(this_box.width+this_box.left>other_box.width+other_box.left &&
       this_box.top+this_box.height>other_box.top){
        return RIGHT;
    }
    if(this_box.top+this_box.height<other_box.top){
        return UNDER;
    }
    return UNKNOWN;
}

