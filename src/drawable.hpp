#ifndef _DRAWABLE_HPP
#define _DRAWABLE_HPP

#include <SFML/Graphics.hpp>

class drawable {
protected:
	sf::Vector2f position;
public:
	drawable(sf::Vector2f position);
	virtual void draw(sf::RenderWindow & window) = 0;
};

#endif
