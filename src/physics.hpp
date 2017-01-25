#ifndef PHYSICS_HPP
#define PHYSICS_HPP

#include "collisionable.hpp"
#include "moveable.hpp"

class physics: public collisionable, public moveable
{
protected:
    sf::Vector2f gravitational_acceleration{ 0, 1 };
    sf::Vector2f previous_position;
public:
	physics(sf::Vector2f position, sf::Vector2f size);
	virtual void update_position(std::vector<collisionable*>& collisionables) = 0;
	virtual void update_gravity() = 0;
    virtual void update_air_resistance(sf::Vector2f& speed) = 0;
    bool check_new_position(std::vector<collisionable*>& collisionables);
    void handle_collision(collisionable & other);
};

#endif
