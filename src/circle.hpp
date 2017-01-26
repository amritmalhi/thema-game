#ifndef circle_HPP
#define circle_HPP

#include <SFML/Graphics.hpp>
#include "moveable.hpp"
#include "drawable.hpp"

class circle : public drawable
{
private:
	sf::CircleShape circle_shape;
protected:
	sf::Vector2f position;
	float radius;
public:
	circle(sf::Vector2f pos,
		float size,
		sf::Color color = sf::Color::Red);
	void draw(sf::RenderWindow & window) override;
	void set_texture() override;
};

#endif //circle_HPP
