#include "circle.hpp"

circle::circle(sf::Vector2f pos, float radius, sf::Color color) :
	drawable(color),
	position(pos),
	radius(radius)
{

}

void circle::draw(sf::RenderWindow & window)
{
	circle_shape.setRadius(radius);
	circle_shape.setPosition(position);
	circle_shape.setFillColor(color);
	window.draw(circle_shape);
}

void circle::set_texture() {
	circle_shape.setTexture(&texture);
}
