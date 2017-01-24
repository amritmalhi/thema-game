#include "window.hpp"
#include <iostream>
/*///===============================================
  FILE:       window.cpp
  AUTHOR:     Stefan de Beer
  DATE:       2017-01-24
/*///===============================================

window::window(sf::String window_title, sf::Vector2f window_size):
    sf::RenderWindow(sf::VideoMode(window_size.x, window_size.y), window_title,
                     sf::Style::Resize+
                     sf::Style::Close
                     ),
    window_size(window_size)
{}

void window::set_target(character & target){
    sf::Vector2f target_pos = target.get_position();
    sf::Vector2f target_size = target.get_size();
    sf::View view;
    target_pos.x = target_pos.x-target_size.x/2;
    target_pos.y = target_pos.y-target_size.y/2;
    view.setSize(window_size.x, window_size.y);
    view.setCenter(target_pos);
    setView(view);
}

void window::resize(){
    sf::Vector2u new_size = getSize();
    window_size.x = (float)new_size.x;
    window_size.y = (float)new_size.y;
}


