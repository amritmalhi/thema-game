#include "drawable.hpp"
#include <iostream>
drawable::drawable( sf::Color color ) :
	color(color)
{}

void drawable::add_texture(std::map<std::string, sf::Texture> & textures, std::string & texture_file_name) {
	if (texture_file_name == "None") {
		return;
	}
	sf::Texture texture;
	auto & texture_iterator = textures.find(texture_file_name);
	if (texture_iterator != textures.end()) {
		texture = texture_iterator->second;
	}
	else {
		if (!texture.loadFromFile(texture_file_name)) {
			std::cout << "Unable to load! " << texture_file_name << std::endl;
			return;
		}
		textures[texture_file_name] = texture;
	}
	set_texture(&textures[texture_file_name]);
}