#include "wall.hpp"
/*///===============================================
  FILE:       wall.cpp
  AUTHOR:     Stefan de Beer
  DATE:       2017-01-20
/*///===============================================
wall::wall(sf::Vector2f position, sf::Vector2f size, sf::Color color):
    rectangle(position, size, color),
    collisionable(position, size)
{}

