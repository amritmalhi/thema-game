#include "rectangle.hpp"

rectangle::rectangle(sf::Vector2f position, sf::Vector2f size, sf::Color color) :
	drawable(color),
	object(position, size)
{}

void rectangle::draw(sf::RenderWindow & window)
{
	sf::RectangleShape myRect;
	myRect.setSize(size);
	myRect.setPosition(position);
	myRect.setFillColor(color);
	window.draw(myRect);
}

