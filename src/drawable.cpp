#include "drawable.hpp"
#include <iostream>
drawable::drawable( sf::Color color ) :
	color(color)
{}

void drawable::add_texture(std::map<std::string, sf::Texture> & textures, std::string & texture_file_name) {
	if (texture_file_name == "None") {
		return;
	}
	try {
		sf::Texture& texture = textures[texture_file_name];
	}
	catch (std::exception & e) {
		sf::Texture texture;
		if (!texture.loadFromFile(texture_file_name)) {
			std::cout << "Unable to load! " << texture_file_name << std::endl;
		}
		textures[texture_file_name] = texture;
	}
	set_texture(&textures[texture_file_name]);
}