#ifndef _LINE_HPP
#define _LINE_HPP

#include <SFML/Graphics.hpp>
#include "rectangle.hpp"

class line : public rectangle {
private:
	float thickness;
public:
	line(sf::Vector2f position, sf::Vector2f size, float thickness, sf::Color color = sf::Color::Red);
	void draw(sf::RenderWindow & window);
};

#endif
