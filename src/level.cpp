/* ==========================================================================
   File: level.cpp
   ========================================================================== */

#include "level.hpp"
#include "factory.hpp"

#include <iostream>
#include <fstream>

#include "character.hpp"
#include "wall.hpp"

level::level()
{

}

level::level(std::string fname)
{
    load_level_from_file(fname);
}

level::~level()
{
    physics_objects.clear();
    collisionables.clear();
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

void level::update()
{
    for (auto& i : physics_objects)
    {
        i->gravity();
        i->update_gravity();

        for (auto& j : collisionables) {
            if (i != j) {
                if (i->detect_collision(*j)) {
                    i->handle_collision(*j);
                }
            }
        }
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
                    physics_objects.push_back((character*) d);
                    collisionables.push_back((character*) d);
                } else if (type == object_wall) {
                    collisionables.push_back((wall*) d);
                }
            } catch (end_of_file& e) {
                break;
            }
        }
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
