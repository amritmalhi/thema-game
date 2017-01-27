#ifndef LEVEL_BUTTON_H
#define LEVEL_BUTTON_H

#include "object.hpp"
#include "rectangle.hpp"
#include "collisionable.hpp"
#include <SFML/Graphics.hpp>

class level_button : public rectangle, public collisionable
{
public:
	level_button(sf::Vector2f position, sf::Vector2f size, sf::Color color);
	virtual void activate();
};

#endif //lEVEL_BUTTON_H