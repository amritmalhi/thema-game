#ifndef _DRAWABLE_HPP
#define _DRAWABLE_HPP

#include <SFML/Graphics.hpp>

///Class is for drawing shapes on the screen.
class drawable {
protected:
	sf::Color color;
    sf::Texture texture;
public:
    ///Constructor takes a color.
	drawable( sf::Color color = sf::Color::Red);

    ///Absolute virtual function for drawing on the screen.
    ///Takes a sf::renderWindow on which the shapes should be drawn.
	virtual void draw(sf::RenderWindow & window) = 0;

    ///Gives a texture too the drawable.
    ///Takes a std::map of texture name and a sf::Texture reference. Alse takes a texture file_name.
	void add_texture(std::map<std::string, sf::Texture> & textures, std::string & texture_file_name);

    ///Aply texture to drawable.
	virtual void set_texture() = 0;
};

#endif
