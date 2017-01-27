#include "level_button.hpp"
#include <iostream>

level_button::level_button(sf::Vector2f position, sf::Vector2f size, sf::Color color) :
	rectangle(position, size, color),
	collisionable(position, size, object_level_button)
{

}
void level_button::activate() {
	std::cout << "activated" << std::endl;
}