#include "character.hpp"

character::character(sf::Vector2f position,sf::Vector2f size, sf::Vector2f speed, sf::Color color):
    rectangle(position, size, color),
    moveable(speed),
    physics(position, size)
{}

void character::update(){
    previous_position = physics::position;
    rectangle::position+=speed;
    physics::position = rectangle::position;
}

void character::move(sf::Vector2f offset){
    rectangle::position +=offset;
    physics::position = rectangle::position;
}

void character::move_left(){
    rectangle::position.x-=speed.x;
    physics::position = rectangle::position;
}

void character::move_right(){
    rectangle::position.x+=speed.x;
    physics::position = rectangle::position;
}

void character::move_up() {
	fall_speed = -speed.y;
}

void character::gravity() {
	rectangle::position.y += fall_speed;
    physics::position = rectangle::position;
}

void character::update_gravity() {
	if (fall_speed <= max_fall_speed){
		fall_speed += mass;
	}
}

void character::draw(sf::RenderWindow & window){
    rectangle::position = physics::position;
    rectangle::draw(window);
}
