#include "killbox.hpp"
#include <iostream>
/*///===============================================
  FILE:       killbox.cpp
  AUTHOR:     Stefan de Beer
  DATE:       2017-01-24
/*///===============================================

killbox::killbox(sf::Vector2f position, sf::Vector2f size, sf::Color color):
    wall(position, size, color)
{}
/*
bool killbox::detect_collision(character & other){
    sf::Vector2f other_pos = other.get_position();
    sf::Vector2f other_size = other.get_size();

    sf::Vector2f this_pos = collisionable::get_position();
    sf::Vector2f this_size = collisionable::get_size();
    
    sf::FloatRect this_box(this_pos, this_size);
    sf::FloatRect other_box(other_pos, other_size);
    return (this_box.intersects(other_box));
       
}
*/
