#ifndef _LINE_HPP
#define _LINE_HPP

#include <SFML/Graphics.hpp>
#include "rectangle.hpp"

///Class for drawing a line.
class line : public rectangle {
private:
	float thickness;
public:
    ///Constructor takes position, size, thickness and color.
    ///Color has the default value of sf::Color::Red.
	line(sf::Vector2f position, sf::Vector2f size, float thickness, sf::Color color = sf::Color::Red);

    ///For drawing the line on the screen.
    ///Takes a sf::RenderWindow.
    void draw(sf::RenderWindow & window);
};

#endif
