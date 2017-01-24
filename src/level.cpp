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

character& level::get_current_target()
{
    return *trackables[current_trackable];
}

void level::next_controllables()
{
    current_trackable++;
    if(current_trackable >= trackables.size()){
        current_trackable = 0;
    }
}

level::level(std::string fname)
{
    load_level_from_file(fname);
}

level::~level()
{
    trackables.clear();
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
        i->handle_input(collisionables);
    }
}

void level::update()
{
    for (auto& i : physics_objects)
    {
        i->gravity(collisionables);
        i->update_gravity();
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
                    controllables.push_back((character*) d);
                    collisionables.push_back((character*) d);
                    trackables.push_back((character*) d);
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
