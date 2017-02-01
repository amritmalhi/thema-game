#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "rectangle.hpp"
#include "moveable.hpp"
#include "controllable.hpp"
#include <SFML/Graphics.hpp>
#include "physics.hpp"
#include "collisionable.hpp"

///The character class. This class is the character you controll.
class character : public rectangle, public moveable,
                  public controllable, public physics{
private:
	float max_fall_speed = 15;
    float max_horizontal_speed = 10;
	float gravity_modifier = 1;
    sf::Vector2f spawn_point;
    ///This function sets the character the right speed to 0 if the character collides with a object.
    ///Takes a collision_direction and a buffer_pos.
    void handle_collision_impassables(collision_direction detected_collision,
                                                 sf::Vector2f buffer_pos);
public:
    ///The constructor. takes a position, size, speed and a color.
    ///Also sets the object_type to object_character.
	character(sf::Vector2f position,
              sf::Vector2f size,
              sf::Vector2f speed,
              sf::Color color = sf::Color::Red);
    
    ///This function set the speed so the character will move to the right.
    ///This function is an overrid from controllable.
    ///Takes a float which is for controller support.
    void move_right(float speed_modifier = 1) override;
    
    ///This function set the speed so the character will move to the left.
    ///This function is an overrid from controllable.
    ///Takes a float which is for controller support.
    void move_left(float speed_modifier = 1) override;
    
    ///This function set the speed so the character will jump.
    ///This function is an overrid from controllable.
    ///Takes a float which is for controller support.
    ///Also takes a std::vector of collisionable.
    ///This is to check if the character is standing on something so it can´t jump mid-air.
	void move_up(std::vector<collisionable*>& collisionables) override;
    
    ///This function makes the character makes the character fall down.
	void update_gravity();
    
    ///This function draws the character on the screen.
    ///Takes a sf::renderWindow by reference.
    ///This is an override from drawable.
    void draw(sf::RenderWindow & window) override;
    
    ///Returns the character position.
    sf::Vector2f get_position();
    
    ///Return the character size.
    sf::Vector2f get_size();
    
    ///Sets the character position to its first spawn position.
    void respawn();
    
    ///This function handles all the different types of collisions
    ///Takes a std::vector of collisionable pointers.
    void update_position(std::vector<collisionable*>& collisionables)override;
    
    ///This function slows the character down when user doesn´t press right or left key.
    void update_air_resistance()override;
};

#endif //CHARACTER_HPP
