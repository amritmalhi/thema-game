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

class level
{
private:
    std::vector<std::shared_ptr<drawable>> drawables;
    std::vector<controllable*> controllables;
    std::vector<collisionable*> collisionables;
    std::vector<physics*> physics_objects;

public:
    level();
    level(std::string fname);
    ~level();

    void draw(sf::RenderWindow& window);
    void handle_input();
    void update();

    void load_level_from_file(std::string fname);
};

#endif // LEVEL_H
