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
    void update()override;
    void move(sf::Vector2f offset)override;
    void move_right()override;
    void move_left()override;
	void move_up()override;
	void gravity();
	void update_gravity();
    void draw(sf::RenderWindow & window) override;
};

#endif //CHARACTER_HPP
