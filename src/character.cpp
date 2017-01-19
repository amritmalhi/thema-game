#include "character.hpp"

character::character(sf::Vector2f position,sf::Vector2f size, sf::Vector2f speed,sf::Color color):
    rectangle(position, size, color),
    moveable(speed)//,
  //controllable(sf::Keyboard::Left, sf::Keyboard::Right)
{}

void character::update(){
    position+=speed;
}

void character::move(sf::Vector2f offset){
    position += offset;
}

void character::move_left(){
    position-=speed;
}

void character::move_right(){
    position+=speed;
}
