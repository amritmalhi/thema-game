#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "rectangle.hpp"
#include "moveable.hpp"
#include "controllable.hpp"
#include <SFML/Graphics.hpp>

class character : public rectangle, public moveable, public controllable{
private:
    sf::Keyboard::Key move_up_key;
    sf::Keyboard::Key move_down_key;
  
public:
    character(sf::Vector2f position, sf::Vector2f size, sf::Vector2f speed, sf::Color color=sf::Color::Red);
    void update()override;
    void move(sf::Vector2f offset)override;
    void move_right()override;
    void move_left()override;
};

#endif //CHARACTER_HPP
