#include <SFML\Graphics.hpp>

class drawable {
private:
	sf::Vector2f position;
public:
	drawable(sf::Vector2f position);
	virtual void draw(sf::RenderWindow & window) = 0;
};