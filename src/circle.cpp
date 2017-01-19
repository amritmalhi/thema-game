#include "circle.hpp"

circle::circle(sf::Vector2f pos, float radius, sf::Color color) :
	drawable(color),
	position(pos),
	radius(radius)
{

}

void circle::draw(sf::RenderWindow & window)
{
	sf::CircleShape myCirc;
	myCirc.setRadius(radius);
	myCirc.setPosition(position);
	myCirc.setFillColor(color);
	window.draw(myCirc);
}

