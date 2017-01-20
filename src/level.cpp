/* ==========================================================================
   File: level.cpp
   ========================================================================== */

#include "level.hpp"
#include "factory.hpp"

#include <iostream>
#include <fstream>

#include "character.hpp"

level::level()
{

}

level::level(std::string fname)
{
    load_level_from_file(fname);
}

level::~level()
{
    controllables.clear();
    drawables.clear();
}

void level::draw(sf::RenderWindow& window)
{
    for (auto& i : drawables)
    {
        i->draw(window);
    }
}

void level::handle_input()
{
    for (auto& i : controllables)
    {
        i->handle_input();
    }
}

void level::load_level_from_file(std::string fname)
{
    try {
        std::ifstream file(fname);
        while (true)
        {
            try {
                int type;
                drawable* d = load_object(file, type);

                drawables.push_back(std::shared_ptr<drawable>(d));
                if (type == object_character) {
                    controllables.push_back((character*) d);
                }
            } catch (end_of_file& e) {
                break;
            }
        }
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
