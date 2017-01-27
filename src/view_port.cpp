#include "view_port.hpp"
/*///===============================================
  FILE:       view_port.cpp
  AUTHOR:     Stefan de Beer
  DATE:       2017-01-24
/*///===============================================

view_port::view_port (sf::RenderWindow & window, sf::Vector2f size):
    window(window),
    size(size)
{}

void view_port::center_viewport_on(object & target)
{
    sf::View view;
    sf::Vector2f target_pos = target.get_position();
    view.setViewport(sf::FloatRect(0, 0, size.x, size.y));
    //sf::Vector2f target_size = target.get_size();
    //target_pos.x = target_size.x/2;
    //target_pos.y = target_size.y/2;
    view.setCenter(target_pos);
    window.setView(view);
}


