#ifndef VIEW_PORT_H
#define VIEW_PORT_H

#include "object.hpp"
#include <SFML/Graphics.hpp>

/*///===============================================
  FILE:       view_port.hpp
  AUTHOR:     Stefan de Beer
  DATE:       2017-01-24
/*///===============================================

class view_port{
private:
    sf::Vector2f size;
    sf::RenderWindow & window;
public:
    view_port(sf::RenderWindow & window, sf::Vector2f size);
    void center_viewport_on(object & target);
    sf::View get_viewport();
};

#endif //VIEW_PORT_H
