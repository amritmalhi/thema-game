#ifndef COLLISIONABLE_H
#define COLLISIONABLE_H

#include "SFML/Graphics.hpp"
#include "object.hpp"
#include <vector>
#include <array>

enum object_position{
    UNKNOWN,
    LEFT,
    RIGHT,
    ABOVE,
    UNDER
};
///This struct contains 4 boolean directions which will be set to true if that side collides.
struct collision_direction{
    bool left = false;
    bool right = false;
    bool above = false;
    bool under = false;
};

///This class is for handling collision.
class collisionable: public object{
public:
    ///the constructor takes a position, size and object_type.
    collisionable(sf::Vector2f position,
                  sf::Vector2f size,
                  object_type type);

    ///Returns true if this collidable is in another collidable.
    ///Takes another collisionable reference. 
    bool detect_collision(collisionable & other);

    ///virtual function for detecting collision with a std::vector of collisionable pointers with a given offset.
	virtual bool detect_collision_position(std::vector<collisionable*>& collisionables,
                                           sf::Vector2f offset = sf::Vector2f(0, 0)) { return false; }

    ///Virtual function for detecting collision with a single collisionable reference with a given offset.
    virtual bool detect_collision_position(collisionable & other,
                                           sf::Vector2f offset = sf::Vector2f(0, 0)) { return false; }

    ///virtual function for handling all the different types of collision.
    ///Takes a std::vector of collisionable pointers and a buffer position.
	virtual void handle_collision(std::vector<collisionable*>& collisionables,
                                  sf::Vector2f buffer_pos) {}

    ///Virtual fuction for returning where the objects collides in a collision_direction.
    ///Takes a std::vector of collisionable pointers.
	virtual collision_direction detect_collision_direction(std::vector<collisionable*>& collisionables
                                                           , sf::Vector2f offset = sf::Vector2f(1, 1))
    {      
        return collision_direction{};
    }

    ///Virtual function for returing where the object collides in a collision_direction.
    ///Takes a single collisionable pointer.
    virtual collision_direction detect_collision_direction(collisionable & other,
                                                           sf::Vector2f offset = sf::Vector2f(1, 1))
    {
        return collision_direction{};
    }
};

#endif //COLLISIONABLE_H
