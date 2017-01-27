#ifndef WALL_H
#define WALL_H

#include "object.hpp"
#include "rectangle.hpp"
#include "collisionable.hpp"
#include "SFML/Graphics.hpp"

/*///===============================================
  FILE:       wall.hpp
  AUTHOR:     Stefan de Beer
  DATE:       2017-01-20
/*///===============================================

class wall : public rectangle, public collisionable{
public:
    wall(sf::Vector2f position, sf::Vector2f size, sf::Color color, object_type type = object_wall);
};

#endif //WALL_H
