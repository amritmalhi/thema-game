#include <SFML/Graphics.hpp>
#include "drawable.hpp"

///Class for drawing text on the screen.
class text : public drawable {
private:
	sf::Vector2f position;
	sf::Text string;
	sf::Font font;
public:
    ///Constructor takes position and the text to bes displayed.
	text(sf::Vector2f position, std::string & message);
    
    ///For drawing the rectangle on the screen.
    ///Takes a sf::RenderWindow. 
	void draw(sf::RenderWindow & window);

    ///Does nothing.
	void set_texture();
};
