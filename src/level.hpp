#ifndef LEVEL_H
/* ==========================================================================
   File: level.hpp
   ========================================================================== */
#define LEVEL_H

#include <memory>
#include <list>
#include <string>

#include <SFML/Graphics.hpp>

#include "drawable.hpp"

class level
{
private:
    std::list<std::shared_ptr<drawable>> drawables;

public:
    level();
    level(std::string fname);
    ~level();

    void draw(sf::RenderWindow& window);

    void load_level_from_file(std::string fname);
};

#endif // LEVEL_H
