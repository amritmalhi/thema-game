/* ==========================================================================
   File: factory.cpp
   ========================================================================== */

#include "factory.hpp"

#include <iostream>
#include <fstream>

#include "rectangle.hpp"
#include "line.hpp"
#include "circle.hpp"

drawable* load_object(std::ifstream& input)
{
    std::string name;
    input >> name;
    input.exceptions(std::ifstream::failbit);

    if (name == "rectangle") {
        float x, y, width, height;
        try {
            input >> x >> y >> width >> height;
        } catch (std::exception& e) {
            throw parse_exception(name);
        }

        rectangle* rect = new rectangle(sf::Vector2f(x, y),
                                        sf::Vector2f(width, height));
        return rect;
    } else if (name == "linerotated") {
        float x, y, width, height, rotation;
        try {
            input >> x >> y >> width >> height >> rotation;
        } catch (std::exception& e) {
            throw parse_exception(name);
        }

        line* l = new line(sf::Vector2f(x, y),
                              sf::Vector2f(width, height),
                              rotation);
        return l;
    } else if (name == "circle") {
        float x, y, size;
        try {
            input >> x >> y >> size;
        } catch (std::exception& e) {
            throw parse_exception(name);
        }

        circle* c = new circle(sf::Vector2f(x, y), size);
        return c;
    } else if (name == "") {
        throw end_of_file();
    }

    throw unknown_shape(name);
}
