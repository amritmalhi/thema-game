#ifndef PHYSICS_HPP
#define PHYSICS_HPP

#include "collisionable.hpp"

class physics : public collisionable
{
protected:
	float fall_speed = 0;
	float gravitational_acceleration = 0.2;
	sf::Vector2f previous_position;
public:
	physics(sf::Vector2f position, sf::Vector2f size, object_type type);
	virtual void gravity(std::vector<collisionable*>& collisionables) = 0;
	virtual void update_gravity() = 0;
    bool check_new_position(std::vector<collisionable*>& collisionables);
    void handle_collision(collisionable & other);
    object_position detect_collision_position(std::vector<collisionable*>& collisionables)override;
};

#endif
