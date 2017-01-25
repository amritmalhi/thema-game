#ifndef _DRAWABLE_HPP
#define _DRAWABLE_HPP

#include <SFML/Graphics.hpp>

class drawable {
protected:
	sf::Color color;
public:
	drawable( sf::Color color = sf::Color::Red);
	virtual void draw(sf::RenderWindow & window) = 0;
	void add_texture(std::map<std::string, sf::Texture> & textures, std::string & texture_file_name);
	virtual void set_texture(sf::Texture * texture) = 0;
};

#endif
