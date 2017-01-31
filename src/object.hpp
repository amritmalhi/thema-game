#ifndef OBJECT_H
#define OBJECT_H

#include "SFML/Graphics.hpp"

/*///===============================================
  FILE:       object.hpp
  AUTHOR:     Stefan de Beer
  DATE:       2017-01-20
/*///===============================================

enum object_type {
    object_rectangle,
    object_line,
    object_circle,
    object_character,
    object_wall,
	object_level_button,
	object_level_lever,
    object_endpoint,
    object_killbox,
	object_text,
    object_end_box
};

class object{
private:
    object_type type;

protected:
    sf::Vector2f position;
    sf::Vector2f size;
public:
    object(sf::Vector2f position,
           object_type type,
           sf::Vector2f size = sf::Vector2f(100, 100)):
    position(position),
    size(size),
    type(type)
    {

    }
    sf::Vector2f get_position();
    sf::Vector2f get_size();
    object_type get_object_type();
};

#endif //OBJECT_H
