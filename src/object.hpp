#ifndef OBJECT_H
#define OBJECT_H

#include "SFML/Graphics.hpp"

/*///===============================================
  FILE:       object.hpp
  AUTHOR:     Stefan de Beer
  DATE:       2017-01-20
/*///===============================================

class object{
protected:
    sf::Vector2f position;
    sf::Vector2f size;
public:
    object(sf::Vector2f position, sf::Vector2f size = sf::Vector2f(100, 100)):
        position(position), size(size)
    {}
};

#endif //OBJECT_H
