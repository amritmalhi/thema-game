#ifndef WALL_H
#define WALL_H

#include "object.hpp"
#include "rectangle.hpp"
#include "collisionable.hpp"
#include "SFML/Graphics.hpp"

///Class for displaying a wall.
class wall : public rectangle, public collisionable{
public:
    ///Constructor takes a position, size, color and object_type.
    ///object_type is set to object_wall by default.
    wall(sf::Vector2f position, sf::Vector2f size, sf::Color color, object_type type = object_wall);
};

#endif //WALL_H
