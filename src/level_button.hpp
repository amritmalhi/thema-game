#ifndef LEVEL_BUTTON_H
#define LEVEL_BUTTON_H

#include "object.hpp"
#include "rectangle.hpp"
#include "collisionable.hpp"
#include <SFML/Graphics.hpp>

///Clas for a button.
class level_button : public rectangle, public collisionable
{
public:
    ///Constructor takes a position, size and color.
	level_button(sf::Vector2f position, sf::Vector2f size, sf::Color color);

    ///What the button wil do when it gets activated.
	virtual void activate();
};

#endif //lEVEL_BUTTON_H
