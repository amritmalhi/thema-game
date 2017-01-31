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
	//virtual void gravity(std::vector<collisionable*>& collisionables) = 0;
	virtual void update_gravity() = 0;
	bool check_new_position(std::vector<collisionable*>& collisionables);
    bool detect_collision_position(std::vector<collisionable*>& collisionables,
                                   sf::Vector2f offset = sf::Vector2f(0, 0))override;
    bool detect_collision_position(collisionable & other,
                                   sf::Vector2f offset = sf::Vector2f(0, 0))override;
    
    void handle_collision(collisionable & other, sf::Vector2f buffer_pos);
    collision_direction detect_collision_direction(std::vector<collisionable*>& collisionables,
                                                   sf::Vector2f offset = sf::Vector2f(1, 1))override;
    collision_direction detect_collision_direction(collisionable & other,
                                                   sf::Vector2f offset = sf::Vector2f(1, 1))override;
    virtual void update_air_resistance(){}
    virtual void update_position(std::vector<collisionable*>& collisionables){}
};

#endif
