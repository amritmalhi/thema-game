#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "rectangle.hpp"
#include "controllable.hpp"
#include <SFML/Graphics.hpp>
#include "physics.hpp"
#include "collisionable.hpp"

class character : public rectangle, public controllable,
                                    public physics{
private:
    sf::Keyboard::Key move_down_key;
    sf::Vector2f max_fall_acceleration{ 0, 8 };
    sf::Vector2f gravity_modifier{ 0, 1 };


public:
	character(sf::Vector2f position,
              sf::Vector2f size,
              sf::Color color = sf::Color::Red);
    void move_right(std::vector<collisionable*>& collisionables, float acceleration_modifier = 1) override;
    void move_left(std::vector<collisionable*>& collisionables, float acceleration_modifier = 1) override;
	void move_up(std::vector<collisionable*>& collisionables) override;
	void update_position(std::vector<collisionable*>& collisionables);
	void update_gravity();
    void update_air_resistance(sf::Vector2f& speed);
    void draw(sf::RenderWindow & window) override;
};

#endif //CHARACTER_HPP
