#include "level_button.hpp"

level_button::level_button(sf::Vector2f position, sf::Vector2f size, sf::Color color) :
	rectangle(position, size, color),
	collisionable(position, size)
{}
