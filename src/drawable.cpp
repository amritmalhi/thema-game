#include "drawable.hpp"
#include <iostream>
drawable::drawable( sf::Color color ) :
	color(color)
{}

void drawable::add_texture(std::map<std::string, sf::Texture> & textures, std::string & texture_file_name) {
	if (texture_file_name == "None") {
		return;
	}
	const auto & texture_iterator = textures.find(texture_file_name);
	if (texture_iterator != textures.end()) {
		texture = sf::Texture(texture_iterator->second);
	}
	else {
		if (!texture.loadFromFile(texture_file_name)) {
			std::cout << "Unable to load! " << texture_file_name << std::endl;
			return;
		}
		textures[texture_file_name] = sf::Texture(texture);
	}
	set_texture();
}
