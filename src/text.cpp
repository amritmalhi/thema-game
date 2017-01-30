#include "text.hpp"
#include "defines.hpp"

text::text(sf::Vector2f position, std::string & message):
	drawable(sf::Color::White),
	position(position)
{
	font.loadFromFile(RES_LOC "res/Android.ttf");
	string.setString(message);
	string.setFont(font);
	string.setPosition(position);
	string.setColor(color);
	string.setCharacterSize(30);
}

void text::draw(sf::RenderWindow & window) {
	window.draw(string);
}

void text::set_texture() {
	return;
}