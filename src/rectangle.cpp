#include "rectangle.hpp"

rectangle::rectangle(sf::Vector2f position, sf::Vector2f size, sf::Color color) :
	drawable(color),
	object(position, size)
{}

void rectangle::draw(sf::RenderWindow & window)
{
	rectangle_shape.setSize(size);
	rectangle_shape.setPosition(position);
	rectangle_shape.setFillColor(color);
	window.draw(rectangle_shape);
}

void rectangle::set_texture(sf::Texture* texture) {
	rectangle_shape.setTexture(texture);
}
