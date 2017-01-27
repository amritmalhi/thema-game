#include "character.hpp"
#include <iostream>

character::character(sf::Vector2f position,sf::Vector2f size, sf::Vector2f speed, sf::Color color):
rectangle(position, size, color),
moveable(speed),
physics(position, size, object_character),
spawn_point(position)
{

}

void character::move_left(std::vector<collisionable*>& collisionables, float speed_modifier){
    float x = physics::position.x;
    physics::position.x -= speed.x * speed_modifier;
    if (check_new_position(collisionables)) {
        physics::position.x = x;
        return;
    }
    rectangle::position = physics::position;
}

void character::move_right(std::vector<collisionable*>& collisionables, float speed_modifier){
    float x = physics::position.x;
    physics::position.x += speed.x * speed_modifier;
    if (check_new_position(collisionables)) {
        physics::position.x = x;
        return;
    }
    rectangle::position = physics::position;
}

void character::move_up(std::vector<collisionable*>& collisionables) {
    float y = physics::position.y;
    physics::position.y += 1;
    if (check_new_position(collisionables)) {
        fall_speed = -speed.y;
    }
    physics::position.y = y;
}

void character::gravity(std::vector<collisionable*>& collisionables) {
    float y = physics::position.y;
	physics::position.y += fall_speed;
    if (check_new_position(collisionables)) {
        fall_speed = 0;
        physics::position.y = y;
        return;
    }
    rectangle::position = physics::position;
}

void character::update_gravity() {
	if (fall_speed < max_fall_speed){
		fall_speed += gravitational_acceleration * gravity_modifier;
	}
}

void character::draw(sf::RenderWindow & window){
    rectangle::position = physics::position;
    rectangle::draw(window);
}

sf::Vector2f character::get_position(){
    return physics::position;
}

sf::Vector2f character::get_size(){
    return physics::size;
}

void character::respawn(){
    physics::position = spawn_point;
}
