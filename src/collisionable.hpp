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
	virtual bool detect_collision_position(collisionable & other, sf::Vector2f offset) { return false; }
	virtual void handle_collision(std::vector<collisionable*>& collisionables) {}
	virtual object_position detect_collision_direction(collisionable & other) { return LEFT; }
};

#endif //COLLISIONABLE_H
