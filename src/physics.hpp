#ifndef PHYSICS_HPP
#define PHYSICS_HPP

#include "collisionable.hpp"

///Class for applying physics.
class physics : public collisionable
{
protected:
	float fall_speed = 0;
	float gravitational_acceleration = 0.2;
	sf::Vector2f previous_position;
public:
    ///Constructor takes a position, size and object_type.
	physics(sf::Vector2f position, sf::Vector2f size, object_type type);
	//virtual void gravity(std::vector<collisionable*>& collisionables) = 0;
    ///virtual function for applying gravity
	virtual void update_gravity() = 0;

    ///Function for detecting collision with a std::vector of collisionable pointers with a given offset.
    bool detect_collision_position(std::vector<collisionable*>& collisionables,
                                   sf::Vector2f offset = sf::Vector2f(0, 0))override;

    ///Function for detecting collision with a single collisionable reference with a given offset.
    bool detect_collision_position(collisionable & other,
                                   sf::Vector2f offset = sf::Vector2f(0, 0))override;

    ///Function for handling all the different types of collision.
    ///Takes a std::vector of collisionable pointers and a buffer position.
    void handle_collision(collisionable & other, sf::Vector2f buffer_pos);

    ///Fuction for returning where the objects collides in a collision_direction.
    ///Takes a std::vector of collisionable pointers.
    collision_direction detect_collision_direction(std::vector<collisionable*>& collisionables,
                                                   sf::Vector2f offset = sf::Vector2f(1, 1))override;
    ///Function for returing where the object collides in a collision_direction.
    ///Takes a single collisionable pointer.
    collision_direction detect_collision_direction(collisionable & other,
                                                   sf::Vector2f offset = sf::Vector2f(1, 1))override;
    ///Virtual function for creating air resistance.
    virtual void update_air_resistance(){}

    ///Virtual function for updating position.
    virtual void update_position(std::vector<collisionable*>& collisionables){}
};

#endif
