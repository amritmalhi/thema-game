#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <SFML/Graphics.hpp>
#include "moveable.hpp"
#include "drawable.hpp"
#include "object.hpp"

///Class for drawing rectangles.
class rectangle : public drawable, public object
{
private:
	sf::RectangleShape rectangle_shape;
public:
    ///Constructor takes position, size and color.
    ///Color had default value of sf::Color::Red.
    rectangle(sf::Vector2f position,
              sf::Vector2f size,
              sf::Color color = sf::Color::Red);

    ///For drawing the rectangle on the screen.
    ///Takes a sf::RenderWindow. 
    void draw(sf::RenderWindow & window) override;

    ///Gives rectangle a texture.
	void set_texture() override;
};

#endif //RECTANGLE_HPP
