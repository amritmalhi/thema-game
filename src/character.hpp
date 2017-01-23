#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "rectangle.hpp"
#include "moveable.hpp"
#include "controllable.hpp"
#include <SFML/Graphics.hpp>
#include "physics.hpp"
#include "collisionable.hpp"

class character : public rectangle, public moveable,
                  public controllable, public physics{
private:
    sf::Keyboard::Key move_down_key;
	float max_fall_speed = 8;
	float mass = 0.2;

public:
	character(sf::Vector2f position,
              sf::Vector2f size,
              sf::Vector2f speed,
              sf::Color color = sf::Color::Red);
    void move_right(std::vector<collisionable*>& collisionables) override;
    void move_left(std::vector<collisionable*>& collisionables) override;
	void move_up(std::vector<collisionable*>& collisionables) override;
	void gravity(std::vector<collisionable*>& collisionables);
	void update_gravity();
    void draw(sf::RenderWindow & window) override;
};

#endif //CHARACTER_HPP
