#include "character.hpp"

character::character(sf::Vector2f position,sf::Vector2f size, sf::Vector2f speed, sf::Color color):
    rectangle(position, size, color),
    moveable(speed),
    physics(position, size)
	//,
	//controllable(sf::Keyboard::Left, sf::Keyboard::Right)
{}

void character::update(){
    rectangle::position+=speed;
}

void character::move(sf::Vector2f offset){
    rectangle::position +=offset;
}

void character::move_left(){
    rectangle::position.x-=speed.x;
}

void character::move_right(){
    rectangle::position.x+=speed.x;
}

void character::move_up() {
	rectangle::position.y-=speed.y;
}

void character::gravity() {
	rectangle::position.y += fall_speed;
}

void character::update_gravity() {
	if (fall_speed <= max_fall_speed){
		fall_speed *= mass;
	}
}
