#ifndef LEVEL_LEVER_H
#define LEVEL_LEVER_H

#include "object.hpp"
#include "rectangle.hpp"
#include "collisionable.hpp"
#include "SFML/Graphics.hpp"

///Class for a lever.
class level_lever : public rectangle, public collisionable {
public:
    ///Constructor takes a position, size, and color.
	level_lever(sf::Vector2f position, sf::Vector2f size, sf::Color color);
};


#endif //LEVEL_LEVER_H
