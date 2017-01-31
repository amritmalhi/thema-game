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

void character::move_left(std::vector<collisionable*>& collisionables, float speed_modifier){
    speed.x -= max_speed.x * speed_modifier;
}

void character::move_right(std::vector<collisionable*>& collisionables, float speed_modifier){
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
    std::cout << this << " " << speed.x << " : " << speed.y << std::endl;
    physics::position += speed;
    //handle_collision(collisionables, buffer_pos);
    for(auto& i : collisionables){
        auto detected_direction = detect_collision_direction(*i, speed);
        //std::cout<<this<<' '<<buffer.left<<buffer.right<<buffer.above<<buffer.under<<std::endl;
        if(i != this){
            if(detected_direction.left||detected_direction.right||
               detected_direction.above||detected_direction.under){
                switch(i->get_object_type()){
                case object_wall:
                    handle_collision_impassables(detected_direction, buffer_pos);
                    std::cout<<"wall"<<std::endl;
                    break;
                case object_killbox:
                    respawn();
                    break;
                case object_level_button:
                    //i->activate();
                    std::cout<<"button"<<std::endl;
                    break;
                case object_level_lever:
                    std::cout<<"lever"<<std::endl;
                    break;
                case object_character:
                    handle_collision_impassables(detected_direction, buffer_pos);
                }
            }
        }
    }
    





    
    /*
    //std::cout<<this<<' '<<speed.x<<' '<<speed.y<<std::endl;
    
    update_air_resistance();
    update_gravity();
    sf::Vector2f buffer_pos = physics::position;
    physics::position += speed;
    handle_collision(collisionables, buffer_pos);
    
    auto buffer = detect_collision_direction(collisionables, speed);

    if(buffer.above||buffer.under){
        physics::position.y = buffer_pos.y;
        speed.y = 0;
    }
    if(buffer.left||buffer.right){
        physics::position.x = buffer_pos.x;
        speed.x = 0;
    }
     std::cout<<buffer.left<<buffer.right<<buffer.above<<buffer.under<<std::endl;
    */
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

void character::handle_collision(std::vector<collisionable*>& collisionables, sf::Vector2f buffer_pos){
    update_air_resistance();
    update_gravity();
    //sf::Vector2f buffer_pos = physics::position;
    physics::position += speed;
    handle_collision(collisionables, buffer_pos);
    for(auto& i : collisionables){
        auto buffer = detect_collision_direction(*i, speed);
        std::cout<<this<<' '<<buffer.left<<buffer.right<<buffer.above<<buffer.under<<std::endl;
        if(i != this){
            if(detect_collision(*i)){
                switch(i->get_object_type()){
                case object_wall:
                    if(buffer.above||buffer.under){
                        physics::position.y = buffer_pos.y;
                        speed.y = 0;
                    }
                    if(buffer.left||buffer.right){
                        physics::position.x = buffer_pos.x;
                        speed.x = 0;
                    }
                    std::cout<<"wall"<<std::endl;
                    break;
                case object_killbox:
                    respawn();
                    break;
                case object_level_button:
                    //i->activate();
                    std::cout<<"button"<<std::endl;
                    break;
                case object_level_lever:
                    std::cout<<"lever"<<std::endl;
                    break;
                }
            }
        }
    }  
}
