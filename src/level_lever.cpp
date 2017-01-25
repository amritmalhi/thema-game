#include "level_lever.hpp"

level_lever::level_lever(sf::Vector2f position, sf::Vector2f size, sf::Color color) :
	rectangle(position, size, color),
	collisionable(position, size)
{}

