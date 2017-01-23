#ifndef PHYSICS_HPP
#define PHYSICS_HPP

#include "collisionable.hpp"

class physics: public collisionable
{
protected:
    float fall_speed = 1;
    sf::Vector2f previous_position;
public:
	physics(sf::Vector2f position, sf::Vector2f size); 
	virtual void gravity() = 0;
	virtual void update_gravity() = 0;
    void handle_collision(collisionable & other);
};

#endif
