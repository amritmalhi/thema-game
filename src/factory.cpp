/* ==========================================================================
File: factory.cpp
========================================================================== */

#include "factory.hpp"

#include <iostream>
#include <fstream>
#include <string>

#include "rectangle.hpp"
#include "line.hpp"
#include "circle.hpp"
#include "character.hpp"
#include "wall.hpp"
#include "level_button.hpp"
#include "level_lever.hpp"
#include "text.hpp"
#include "object.hpp"

drawable* load_object(std::ifstream& input, int& type, std::map<std::string, sf::Texture> & textures)
{
	std::string name;
	try {
		input >> name;
	}
	catch (std::exception& e) {
		throw end_of_file();
	}

	input.exceptions(std::ifstream::failbit);

	if (name == "rectangle") {
		float x, y, width, height;
		int r, g, b;
		std::string texture_file_name;
		try {
			input >> x >> y >> width >> height >> r >> g >> b >> texture_file_name;
			if (texture_file_name == "") {
				texture_file_name = "None";
			}
		}
		catch (std::exception& e) {
			throw parse_exception(name);
		}

		rectangle* rect = new rectangle(sf::Vector2f(x, y),
			sf::Vector2f(width, height),
			sf::Color(r, g, b));
		rect->add_texture(textures, texture_file_name);
		type = object_rectangle;
		return rect;
	}
	else if (name == "line") {
		float x, y, xto, yto, rotation;
		int r, g, b;
		try {
			input >> x >> y >> xto >> yto >> rotation >> r >> g >> b;
		}
		catch (std::exception& e) {
			throw parse_exception(name);
		}

		line* l = new line(sf::Vector2f(x, y),
			sf::Vector2f(xto, yto),
			rotation,
			sf::Color(r, g, b));
		type = object_line;
		return l;
	}
	else if (name == "circle") {
		float x, y, size;
		int r, g, b;
		std::string texture_file_name;
		try {
			input >> x >> y >> size >> r >> g >> b >> texture_file_name;
			if (texture_file_name == "") {
				texture_file_name = "None";
			}
		}
		catch (std::exception& e) {
			throw parse_exception(name);
		}

		circle* c = new circle(sf::Vector2f(x, y), size, sf::Color(r, g, b));
        c->add_texture(textures, texture_file_name);
		type = object_circle;
		return c;
	}
	else if (name == "character") {
		float x, y, width, height, speedx, speedy;
		int r, g, b;
        std::string texture_file_name;
		try {
			input >> x >> y >> width >> height >> speedx >> speedy;
			input >> r >> g >> b;
			std::getline(input, texture_file_name);
			texture_file_name.erase(0, 1);
            if (texture_file_name == "") {
				texture_file_name = "None";
			}
		}
		catch (std::exception& e) {
			throw parse_exception(name);
		}

		character* c = new character(sf::Vector2f(x, y),
                                     sf::Vector2f(width, height),
                                     sf::Vector2f(speedx, speedy),
                                     sf::Color(r, g, b));
        c->add_texture(textures, texture_file_name);
		type = object_character;
		return c;
	}
	else if (name == "wall") {
		float x, y, width, height;
		int r, g, b;
		try {
			input >> x >> y >> width >> height >> r >> g >> b;
		}
		catch (std::exception& e) {
			throw parse_exception(name);
		}

		wall* w = new wall(sf::Vector2f(x, y),
			sf::Vector2f(width, height),
			sf::Color(r, g, b));
		type = object_wall;
		return w;

	}
	else if (name == "level_button") {
		float x, y, width, height;
		int r, g, b;
		try {
			input >> x >> y >> width >> height >> r >> g >> b;
		}
		catch (std::exception& e) {
			throw parse_exception(name);
		}

		level_button* l_b = new level_button(sf::Vector2f(x, y),
			sf::Vector2f(width, height),
			sf::Color(r, g, b));
		type = object_level_button;
		return l_b;

	}
	else if (name == "level_lever") {
		float x, y, width, height;
		int r, g, b;
		try {
			input >> x >> y >> width >> height >> r >> g >> b;
		}
		catch (std::exception& e) {
			throw parse_exception(name);
		}

		level_lever* l_l = new level_lever(sf::Vector2f(x, y),
			sf::Vector2f(width, height),
			sf::Color(r, g, b));
		type = object_level_lever;
		return l_l;

	}

    else if (name == "killbox") {
		float x, y, width, height;
		int r, g, b;
		try {
			input >> x >> y >> width >> height >> r >> g >> b;
		}
		catch (std::exception& e) {
			throw parse_exception(name);
		}

		wall* w = new wall(sf::Vector2f(x, y),
			sf::Vector2f(width, height),
            sf::Color(r, g, b),
            object_killbox);
		type = object_wall;
		return w;

	}
    
	else if (name == "text") {
		std::cout << "Hier!" << std::endl;
		float x, y;
		std::string message;
		try {
			input >> x >> y;
			std::getline(input, message, '\0');
			message.erase(0, 1);
		}
		catch (std::exception & e) {
			throw parse_exception(name);
		}
		text* t = new text(sf::Vector2f(x, y), message);
		type = object_text;
		return t;
	}

	else if (name == "") {
		throw end_of_file();
	}

	throw unknown_shape(name);
}
