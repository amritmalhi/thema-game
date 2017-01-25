#ifndef LEVEL_LEVER_H
#define LEVEL_LEVER_H

#include "object.hpp"
#include "rectangle.hpp"
#include "collisionable.hpp"
#include "SFML/Graphics.hpp"

class level_lever : public rectangle, public collisionable {
public:
	level_lever(sf::Vector2f position, sf::Vector2f size, sf::Color color);
};


#endif LEVEL_LEVER_H
