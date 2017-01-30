#include <SFML/Graphics.hpp>
#include "drawable.hpp"

class text : public drawable {
private:
	sf::Vector2f position;
	sf::Text string;
	sf::Font font;
public:
	text(sf::Vector2f position, std::string & message);
	void draw(sf::RenderWindow & window);
	void set_texture();
};