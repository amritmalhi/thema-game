#include "moveable.hpp"

moveable::moveable(sf::Vector2f speed, sf::Vector2f position):
  speed(speed),
  position(position)
{}

void moveable::set_speed(sf::Vector2f new_speed){
  speed = new_speed;
}

void moveable::set_position(sf::Vector2f new_position){
  position = new_position;
}

sf::Vector2f moveable::get_position(){
  return position;
}

sf::Vector2f moveable::get_speed(){
  return speed;
}

void moveable::update(){
  position += speed;
}

void moveable::move(sf::Vector2f offset){
  position+=offset;
}
