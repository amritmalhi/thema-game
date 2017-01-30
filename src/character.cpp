#include "character.hpp"
#include <iostream>
#include "defines.hpp"

character::character(sf::Vector2f position,sf::Vector2f size, sf::Color color):
    rectangle(position, size, color),
    physics(position, size)
{}

void character::move_left(std::vector<collisionable*>& collisionables, float acceleration_modifier){
    speed.x += -10 * acceleration_modifier;
}

void character::move_right(std::vector<collisionable*>& collisionables, float acceleration_modifier){
    speed.x += 10 * acceleration_modifier;
}

void character::move_up(std::vector<collisionable*>& collisionables) {

    sf::Vector2f previous_pos{ physics::position };
    physics::position.y += 1;
    if( check_new_position( collisionables ) ) { // Check if there is something below me
        speed.y += -14;
    }
    physics::position = previous_pos;
}

void character::update_position(std::vector<collisionable*>& collisionables) {
    
    
    sf::Vector2f previous_pos{ physics::position };
    sf::Vector2f previous_speed{ speed };

    update_gravity();
    update_air_resistance();

/*    physics::position.y += -speed.y;
    if (check_new_position(collisionables)) { // check if there is something above me
        speed.y = 0; // Stop moving vertically
        std::cout << "There is something above " << this << std::endl;
    }
    physics::position = previous_pos;

    physics::position.y += speed.y;
    if (check_new_position(collisionables) ) { // check if there is something below me
        speed.y = 0; // Stop moving vertically
        std::cout << "There is something below " << this << std::endl;
    }
    physics::position = previous_pos;

    physics::position.x += -1;
    if (check_new_position(collisionables)) { // check if there is something to the left of me
        speed.x = 0; // Stop moving horizontally
        std::cout << "There is something to the left of " << this << std::endl;
    }
    physics::position = previous_pos;

    physics::position.x += 1;
    if (check_new_position(collisionables)) { // check if there is something to the right of me
        speed.x = 0; // Stop moving horizontally
        std::cout << "There is something to the right of " << this << std::endl;
    }
    physics::position = previous_pos;
*/
    physics::position += speed;
    if (check_new_position(collisionables)) {
        physics::position = previous_pos;
        return;
    }

    rectangle::position += physics::position;
}

void character::update_gravity() {
    speed.y += gravitational_acceleration.y * gravity_modifier.y;
    speed.x += gravitational_acceleration.x * gravity_modifier.x;
}

void character::update_air_resistance() {
    float max_speed_x = 10;
    float max_speed_y = 20;

    if (speed.x > 0) {
        speed.x *= 0.8f;
    }
    else if (speed.x < 0) {
        speed.x *= 0.8f;
    }

    if (speed.x > max_speed_x) {
        speed.x = max_speed_x;
    }
    else if (speed.x < -max_speed_x) {
        speed.x = -max_speed_x;
    }
    if (speed.y > max_speed_y) {
        speed.y = max_speed_y;
    }

    if (speed.y < 0.1 && speed.y > -0.1) {
        speed.y = 0;
    }
    if (speed.x < 0.1 && speed.x > -0.1) {
        speed.x = 0;
    }

    std::cout << this << " - speed :" << speed.x << " : " << speed.y << std::endl;
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
