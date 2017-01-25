#ifndef KILLBOX_H
#define KILLBOX_H

#include "SFML/Graphics.hpp"
#include "wall.hpp"
#include "character.hpp"

/*///===============================================
  FILE:       killbox.hpp
  AUTHOR:     Stefan de Beer
  DATE:       2017-01-24
/*///===============================================

class killbox : public wall{
private:

public:
    killbox(sf::Vector2f position, sf::Vector2f size, sf::Color color=sf::Color::Red);
    //bool detect_collision(character & other);
};

#endif //KILLBOX_H
