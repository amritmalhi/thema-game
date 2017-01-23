#include "character.hpp"

character::character(sf::Vector2f position,sf::Vector2f size, sf::Vector2f speed, sf::Color color):
    rectangle(position, size, color),
    moveable(speed),
    physics(position, size)
{}

void character::move_left(std::vector<collisionable*>& collisionables){
    float x = physics::position.x;
    physics::position.x -= speed.x;
    if (check_new_position(collisionables)) {
        physics::position.x = x;
        return;
    }
    rectangle::position = physics::position;
}

void character::move_right(std::vector<collisionable*>& collisionables){
    float x = physics::position.x;
    physics::position.x += speed.x;
    if (check_new_position(collisionables)) {
        physics::position.x = x;
        return;
    }
    rectangle::position = physics::position;
}

void character::move_up(std::vector<collisionable*>& collisionables) {
	fall_speed = -speed.y;
}

void character::gravity(std::vector<collisionable*>& collisionables) {
    float y = physics::position.y;
	physics::position.y += fall_speed;
    if (check_new_position(collisionables)) {
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
