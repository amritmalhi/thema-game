/* ==========================================================================
   File: level.cpp
   ========================================================================== */

#include "level.hpp"
#include "factory.hpp"

#include <iostream>
#include <fstream>

level::level()
{

}

level::level(std::string fname)
{
    load_level_from_file(fname);
}

level::~level()
{
    drawables.clear();
}

void level::draw(sf::RenderWindow& window)
{
    for (auto& i : drawables)
    {
        i->draw(window);
    }
}

void level::load_level_from_file(std::string fname)
{
    try {
        std::ifstream file(fname);
        while (true)
        {
            try {
                drawables.push_back(
                    std::shared_ptr<drawable>(load_object(file)));
            } catch (end_of_file& e) {
                break;
            }
        }
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
