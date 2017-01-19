#include <SFML/Graphics.hpp>
#include "rectangle.hpp"
#include "line.hpp"
#include <math.h>
#include <iostream>

line::line(sf::Vector2f position, sf::Vector2f size, float thickness, sf::Color color) :
	rectangle(position, size, color),
	thickness(thickness)
{}

void line::draw(sf::RenderWindow & window) {
	sf::RectangleShape line;
	float length = sqrtf(powf(size.x - position.x, 2) + powf(size.y - position.y, 2));
	float angle = atan((size.y - position.y) / (size.x - position.x)) * (180 / (atan(1) * 4));
	line.setSize(sf::Vector2f{ length, thickness });
	line.setPosition(sf::Vector2f{ position.x, position.y - thickness / 2 });
	line.setFillColor(color);
	line.rotate(angle);
	window.draw(line);
}