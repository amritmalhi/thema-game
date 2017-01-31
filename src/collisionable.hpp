#ifndef COLLISIONABLE_H
#define COLLISIONABLE_H

#include "SFML/Graphics.hpp"
#include "object.hpp"
#include <vector>
#include <array>

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

struct collision_direction{
    bool left = false;
    bool right = false;
    bool above = false;
    bool under = false;
};

class collisionable: public object{
public:
    collisionable(sf::Vector2f position,
                  sf::Vector2f size,
                  object_type type);
    bool detect_collision(collisionable & other);
	virtual bool detect_collision_position(std::vector<collisionable*>& collisionables,
                                           sf::Vector2f offset = sf::Vector2f(0, 0)) { return false; }
    virtual bool detect_collision_position(collisionable & other,
                                           sf::Vector2f offset = sf::Vector2f(0, 0)) { return false; }
    
	virtual void handle_collision(std::vector<collisionable*>& collisionables, sf::Vector2f buffer_pos) {}
	virtual collision_direction detect_collision_direction(std::vector<collisionable*>& collisionables
                                                           , sf::Vector2f offset = sf::Vector2f(1, 1))
    {      
        return collision_direction{};
    }

    virtual collision_direction detect_collision_direction(collisionable & other,
                                                           sf::Vector2f offset = sf::Vector2f(1, 1))
    {
        return collision_direction{};
    }
};

#endif //COLLISIONABLE_H
