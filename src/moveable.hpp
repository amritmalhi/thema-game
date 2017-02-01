#ifndef MOVEABLE_HPP
#define MOVEABLE_HPP

#include <SFML/Graphics.hpp>

///This class make aobject moveable.
class moveable{
protected:
    sf::Vector2f max_speed;
    sf::Vector2f speed;
public:
    ///Constructor take a max speed.
    moveable(sf::Vector2f max_speed);

    ///A virtual function for update the position.
    virtual void update(){};

    ///virtual function for changing the position.
    virtual void move(sf::Vector2f offset){}
};

#endif //MOVEABLE_HPP
