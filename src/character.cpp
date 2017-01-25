#include "character.hpp"
#include <iostream>
#include "defines.hpp"

character::character(sf::Vector2f position,sf::Vector2f size, sf::Color color):
    rectangle(position, size, color),
    physics(position, size)
{}

void character::move_left(std::vector<collisionable*>& collisionables, float acceleration_modifier){
    acceleration.x += -10 * acceleration_modifier;
}

void character::move_right(std::vector<collisionable*>& collisionables, float acceleration_modifier){
    acceleration.x += 10 * acceleration_modifier;
}

void character::move_up(std::vector<collisionable*>& collisionables) {

    sf::Vector2f previous_pos{ physics::position };
    physics::position.y += 10;
    if( check_new_position( collisionables ) ) {
        acceleration.y += -20;
    }
    physics::position = previous_pos;
}

void character::update_position(std::vector<collisionable*>& collisionables) {
    

    sf::Vector2f speed{ acceleration.x/2 , acceleration.y/2 };

    sf::Vector2f previous_pos{ physics::position };
    physics::position += speed;

    update_gravity();
    update_air_resistance(speed);


    if (check_new_position(collisionables) ) {
        speed = sf::Vector2f(0.f, 0.f);
        acceleration.y = 0;

        physics::position = previous_pos;
        return;
    }
    {
        if (acceleration.x > 0) {
            acceleration.x *= 0.8f;
        }
        else if (acceleration.x < 0) {
            acceleration.x *= 0.8f;
        }
    }

    rectangle::position += physics::position;
}

void character::update_gravity() {
    acceleration.y += gravitational_acceleration.y * gravity_modifier.y;
    acceleration.x += gravitational_acceleration.x * gravity_modifier.x;
}

void character::update_air_resistance(sf::Vector2f& speed) {
    float max_speed_x = 50;
    float max_speed_y = 50;
    float max_acceleration_x = 10;
    float max_acceleration_y = 10;

    if (speed.x > max_speed_x) {
        speed.x = max_speed_x;
    }
    else if (speed.x < -max_speed_x) {
        speed.x = -max_speed_x;
    }
    if (speed.y > max_speed_y) {
        speed.y = max_speed_y;
    }
    else if (speed.y < -max_speed_y) {
        speed.y = -max_speed_y;
    }

    if (acceleration.x > max_acceleration_x) {
        acceleration.x = max_acceleration_x;
    }
    else if (acceleration.x < -max_acceleration_x) {
        acceleration.x = -max_acceleration_x;
    }
    if (acceleration.y > max_acceleration_y) {
        acceleration.y = max_acceleration_y;
    }
    else if (acceleration.y < -max_acceleration_y) {
        acceleration.y = -max_acceleration_y;
    }
    std::cout << "speed: " << speed.x << " : " << speed.y << std::endl;
    std::cout << "acceleration: " << acceleration.x << " : " << acceleration.y << std::endl;
}

void character::draw(sf::RenderWindow & window){
    rectangle::position = physics::position;
    rectangle::draw(window);
}
