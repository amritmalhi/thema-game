#ifndef circle_HPP
#define circle_HPP

#include <SFML/Graphics.hpp>
#include "moveable.hpp"
#include "drawable.hpp"

///A class for drawing circles.
class circle : public drawable
{
private:
	sf::CircleShape circle_shape;
protected:
	sf::Vector2f position;
	float radius;
public:
    ///Constructor takes a position, size, and color.
    ///Color has a default falue of sf::Color::Red.
	circle(sf::Vector2f pos,
		float size,
		sf::Color color = sf::Color::Red);
    
    ///For drawing the circle on the screen.
    ///takes a sf::RenderWindow reference.
	void draw(sf::RenderWindow & window) override;

    ///Give the circle a texture.
	void set_texture() override;
};

#endif //circle_HPP
