#ifndef COLLISIONABLE_H
#define COLLISIONABLE_H

#include "SFML/Graphics.hpp"
#include "object.hpp"

/*///===============================================
  FILE:       collisionable.hpp
  AUTHOR:     Stefan de Beer
  DATE:       2017-01-20
/*///===============================================

enum object_position{
    UNKNOWN,
    LEFT,
    RIGHT,
    ABOVE,
    UNDER
}; 

class collisionable: public object{
public:
    collisionable(sf::Vector2f position, sf::Vector2f size);
    virtual bool detect_collision(collisionable & other);
    object_position detect_position(collisionable & other);
};

#endif //COLLISIONABLE_H
