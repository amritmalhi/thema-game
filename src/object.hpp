#ifndef OBJECT_H
#define OBJECT_H

#include "SFML/Graphics.hpp"

/*///===============================================
  FILE:       object.hpp
  AUTHOR:     Stefan de Beer
  DATE:       2017-01-20
/*///===============================================
/*!
  This enum has has object_types so other objects can know what the collide with.
 */
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

/*!
  The object_type class. This is a superclass of many shapes.
 */

///This class contains the position, size, color and object_type of most shapes
class object{
private:
    object_type type;

protected:
    sf::Vector2f position;
    sf::Vector2f size;
public:
    /*!
      The constructor takes a position, size and an object_type;
     */
    object(sf::Vector2f position,
           object_type type,
           sf::Vector2f size = sf::Vector2f(100, 100)):
    position(position),
    size(size),
    type(type)
    {}
    ///Return the position of the object.
    sf::Vector2f get_position();
    ///Return the size of the object.
    sf::Vector2f get_size();
    ///Return the object_type of the object.
    object_type get_object_type();
};

#endif //OBJECT_H
