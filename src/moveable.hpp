#ifndef MOVEABLE_HPP
#define MOVEABLE_HPP

#include <SFML/Graphics.hpp>

class moveable{
protected:
    sf::Vector2f acceleration{ 0, 0 };
public:
    moveable();
    virtual void update(){};
    virtual void move(sf::Vector2f offset){}
};

#endif //MOVEABLE_HPP
