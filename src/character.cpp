#include "character.hpp"
#include <iostream>

void character::handle_collision_impassables(collision_direction detected_collision,
                                  sf::Vector2f buffer_pos){
    if(detected_collision.above||detected_collision.under){
        physics::position.y = buffer_pos.y;
        speed.y = 0;
    }
    if(detected_collision.left||detected_collision.right){
        physics::position.x = buffer_pos.x;
        speed.x = 0;
    }
}


character::character(sf::Vector2f position,sf::Vector2f size, sf::Vector2f speed, sf::Color color):
rectangle(position, size, color),
moveable(speed),
physics(position, size, object_character),
spawn_point(position)
{

}

void character::move_left(float speed_modifier){
    speed.x -= max_speed.x * speed_modifier;
}

void character::move_right(float speed_modifier){
    speed.x += max_speed.x * speed_modifier;
}

void character::move_up(std::vector<collisionable*>& collisionables) {
    auto buffer = detect_collision_direction(collisionables);
    if(buffer.under){
        speed.y += -max_speed.y;
    }
}

void character::update_position(std::vector<collisionable*>& collisionables){
    update_air_resistance();
    update_gravity();
    sf::Vector2f buffer_pos = physics::position;
//    std::cout << this << " " << speed.x << " : " << speed.y << std::endl;
    physics::position += speed;
    for(auto& i : collisionables){
        auto detected_direction = detect_collision_direction(*i, speed);
        //std::cout<<this<<' '<<buffer.left<<buffer.right<<buffer.above<<buffer.under<<std::endl;
        if(i != this){
            if(detected_direction.left||detected_direction.right||
               detected_direction.above||detected_direction.under){
                switch(i->get_object_type()){
                case object_wall:
                    handle_collision_impassables(detected_direction, buffer_pos);
//                    std::cout<<"Wall"<<std::endl;
                    break;
                case object_killbox:
                    respawn();
//                    std::cout<<"Killbox"<<std::endl;
                    break;
                case object_level_button:
//                      i->activate();   // Doesn't currently work but is supposed to be handeled here
//                    std::cout<<"Button"<<std::endl;
                    break;
                case object_level_lever:
//                      i->activate();   // Doesn't currently work but is supposed to be handeled here
//                    std::cout<<"Lever"<<std::endl;
                    break;
                case object_character:
                    handle_collision_impassables(detected_direction, buffer_pos);
                    break;
                case object_end_box:
                    // Should tell the level manager to go to the next lever, but can't access the level manager here yet.
                    // To showcase it works, it respawns the player instead, for now.
                    respawn();
//                    std::cout<<"Killbox"<<std::endl;
                    break;
                }
            }
        }
    }
    rectangle::position = physics::position;
    
}

void character::update_air_resistance(){
    speed.x *= 0.8f;
    if(speed.x < 0.1 && speed.x > -0.1){
        speed.x = 0;
    }
    
    if(speed.x > max_speed.x){
        speed.x = max_speed.x;
    }
    
    else if(speed.x < -max_speed.x){
        speed.x = -max_speed.x;
    }

    if (speed.y > 15) {
        speed.y = 15;
    }   
}

void character::update_gravity() {
    speed.y += gravitational_acceleration * gravity_modifier;
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

