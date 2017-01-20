#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "rectangle.hpp"
#include "moveable.hpp"
#include "controllable.hpp"
#include <SFML/Graphics.hpp>
#include "physics.hpp"

class character : public rectangle, public moveable, public controllable, public physics {
private:
    sf::Keyboard::Key move_down_key;
	float fall_speed = 1;
	float max_fall_speed = 3;
	float mass = 1.2;

public:
	character(sf::Vector2f position, sf::Vector2f size, sf::Vector2f speed, sf::Color color = sf::Color::Red);
    void update()override;
    void move(sf::Vector2f offset)override;
    void move_right()override;
    void move_left()override;
	void move_up()override;
	void gravity();
	void update_gravity();
};

#endif //CHARACTER_HPP