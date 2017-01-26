#include "rectangle.hpp"

#include <iostream>

rectangle::rectangle(sf::Vector2f position, sf::Vector2f size, sf::Color color) :
	drawable(color),
	object(position, size)
{
    rectangle_shape.setFillColor(color);
}

void rectangle::draw(sf::RenderWindow & window)
{
	rectangle_shape.setSize(size);
	rectangle_shape.setPosition(position);
	window.draw(rectangle_shape);
}

void rectangle::set_texture() {
	rectangle_shape.setTexture(&texture);
}
