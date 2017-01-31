#ifndef MOVEABLE_HPP
#define MOVEABLE_HPP

#include <SFML/Graphics.hpp>

class moveable{
protected:
    sf::Vector2f max_speed;
    sf::Vector2f speed;
public:
    moveable(sf::Vector2f max_speed);
    virtual void update(){};
    virtual void move(sf::Vector2f offset){}
};

#endif //MOVEABLE_HPP
