
#include "collisionable.hpp"
#include <iostream>
/*///===============================================
  FILE:       collisionable.cpp
  AUTHOR:     Stefan de Beer
  DATE:       2017-01-20
/*///===============================================

collisionable::collisionable(sf::Vector2f position,
                             sf::Vector2f size,
                             object_type type):
object(position, type, size)
{}


bool collisionable::detect_collision(collisionable & other){
    sf::IntRect this_box((int)position.x, (int)position.y, (int)size.x, (int)size.y);
    sf::IntRect other_box((int)other.position.x,
                          (int)other.position.y,
                          (int)other.size.x,
                          (int)other.size.y);
    bool buf = this_box.intersects(other_box);
    return buf;
}
