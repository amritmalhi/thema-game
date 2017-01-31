#include "moveable.hpp"

moveable::moveable(sf::Vector2f speed):
    max_speed(speed),
    speed(sf::Vector2f(0, 0))
{}

