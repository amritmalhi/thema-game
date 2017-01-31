/* ==========================================================================
   File: level.cpp
   ========================================================================== */

#include "level.hpp"
#include "factory.hpp"

#include <iostream>
#include <fstream>

#include "character.hpp"
#include "wall.hpp"
#include "level_button.hpp"

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
    controllables[current_trackable]->handle_input(collisionables);
}

void level::update()
{
    for (auto& i : physics_objects)
    {
        i->update_position(collisionables);
    }
}

void level::handle_collisions(){
    for(auto& i : collisionables){
        //i->handle_collision(collisionables);
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
                drawable* d = load_object(file, type, textures);

                drawables.push_back(std::shared_ptr<drawable>(d));
                if (type == object_character) {
                    controllables.push_back((character*) d);
                    physics_objects.push_back((character*) d);
                    collisionables.push_back((character*) d);
                    trackables.push_back((character*) d);
                } else if (type == object_wall) {
                    collisionables.push_back((wall*) d);
				}
				else if (type == object_level_button) {
					collisionables.push_back((level_button*) d);
				}
            } catch (end_of_file& e) {
                break;
            }
        }
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
