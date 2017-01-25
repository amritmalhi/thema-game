/* ==========================================================================
   File: factory.cpp
   ========================================================================== */

#include "factory.hpp"

#include <iostream>
#include <fstream>

#include "rectangle.hpp"
#include "line.hpp"
#include "circle.hpp"
#include "character.hpp"
#include "wall.hpp"
#include "level_button.hpp"
#include "level_lever.hpp"

drawable* load_object(std::ifstream& input, int& type)
{
    std::string name;
    try {
        input >> name;
    } catch (std::exception& e) {
        throw end_of_file();
    }

    input.exceptions(std::ifstream::failbit);

    if (name == "rectangle") {
        float x, y, width, height;
        int r, g, b;
        try {
            input >> x >> y >> width >> height >> r >> g >> b;
        } catch (std::exception& e) {
            throw parse_exception(name);
        }

        rectangle* rect = new rectangle(sf::Vector2f(x, y),
                                        sf::Vector2f(width, height),
                                        sf::Color(r, g, b));
        type = object_rectangle;
        return rect;
    } else if (name == "line") {
        float x, y, xto, yto, rotation;
        int r, g, b;
        try {
            input >> x >> y >> xto >> yto >> rotation >> r >> g >> b;
        } catch (std::exception& e) {
            throw parse_exception(name);
        }

        line* l = new line(sf::Vector2f(x, y),
                           sf::Vector2f(xto, yto),
                           rotation,
                           sf::Color(r, g, b));
        type = object_line;
        return l;
    } else if (name == "circle") {
        float x, y, size;
        int r, g, b;
        try {
            input >> x >> y >> size >> r >> g >> b;
        } catch (std::exception& e) {
            throw parse_exception(name);
        }

        circle* c = new circle(sf::Vector2f(x, y), size, sf::Color(r, g, b));
        type = object_circle;
        return c;
    } else if (name == "character") {
        float x, y, width, height, accelerationx, accelerationy;
        int r, g, b;
        try {
            input >> x >> y >> width >> height;
            input >> r >> g >> b;
        } catch (std::exception& e) {
            throw parse_exception(name);
        }

        character* c = new character(sf::Vector2f(x, y),
                                     sf::Vector2f(width, height),
                                     sf::Color(r, g, b));
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

	} else if (name == "level_button") {
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

    } else if (name == "") {
        throw end_of_file();
    }

    throw unknown_shape(name);
}
