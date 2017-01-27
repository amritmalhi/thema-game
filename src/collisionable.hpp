#ifndef COLLISIONABLE_H
#define COLLISIONABLE_H

#include "SFML/Graphics.hpp"
#include "object.hpp"
#include <vector>

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
    collisionable(sf::Vector2f position,
                  sf::Vector2f size,
                  object_type type);
    bool detect_collision(collisionable & other);
    virtual object_position detect_collision_position(std::vector<collisionable*>& collisionables){}
    virtual void handle_collision(std::vector<collisionable*>& collisionables, sf::Vector2f offset){}
};

#endif //COLLISIONABLE_H
