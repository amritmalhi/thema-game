#ifndef LEVEL_H
/* ==========================================================================
   File: level.hpp
   ========================================================================== */
#define LEVEL_H

#include <memory>
#include <vector>
#include <string>

#include <SFML/Graphics.hpp>

#include "drawable.hpp"
#include "controllable.hpp"
#include "collisionable.hpp"
#include "physics.hpp"
#include "view_port.hpp"
#include "character.hpp"

class level
{
private:
    std::vector<std::shared_ptr<drawable>> drawables;
    std::vector<controllable*> controllables;
    std::vector<collisionable*> collisionables;
    std::vector<physics*> physics_objects;
    std::vector<character*> trackables;
	std::map<std::string, sf::Texture> textures;
    unsigned int current_trackable = 0;
    
public:
    level();
    level(std::string fname);
    ~level();
    
    void draw(sf::RenderWindow& window);
    void handle_input();
    void update();
    
    void load_level_from_file(std::string fname);

    void handle_collisions();
    
    void next_controllables();
    character& get_current_target();
};

#endif // LEVEL_H
