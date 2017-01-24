#ifndef WINDOW_H
#define WINDOW_H

#include "SFML/Graphics.hpp"
#include "object.hpp"
#include "controllable.hpp"
#include "character.hpp"
//#include <SFML/Drawables.hpp>

/*///===============================================
  FILE:       window.hpp
  AUTHOR:     Stefan de Beer
  DATE:       2017-01-24
/*///===============================================

class window : public sf::RenderWindow{
private:
    sf::Vector2f window_size;
public:
    window(sf::String window_title, sf::Vector2f window_size);
    void set_target(character & target);
    void no_target();
    void resize();
};

#endif //WINDOW_H
