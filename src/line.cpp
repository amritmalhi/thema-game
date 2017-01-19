#include <SFML/Graphics.hpp>
#include "rectangle.hpp"
#include "line.hpp"

line::line(sf::Vector2f position, sf::Vector2f size, float angle, sf::Color color) :
	rectangle(position, size, color),
	angle(angle)
{}

void line::draw(sf::RenderWindow & window) {
	sf::RectangleShape line;
	line.setSize(size);
	line.setPosition(position);
	line.rotate(angle);
	line.setFillColor(color);
	window.draw(line);
}