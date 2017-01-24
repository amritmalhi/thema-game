#ifndef BUTTON_H
/* ==========================================================================
   File: button.hpp
   ========================================================================== */
#define BUTTON_H

#include <SFML/Graphics.hpp>

#include <string>

class menu_button
{
private:
    int ret;
    sf::Vector2f size;
    sf::Text text;
    sf::RectangleShape background;

public:
    menu_button(std::string name,
                int ret,
                sf::Vector2f position = sf::Vector2f(0, 0),
                sf::Vector2f size = sf::Vector2f(500, 70));

    bool check_pressed(int x, int y);

    virtual void draw(sf::RenderWindow& window);
    virtual void set_position(sf::Vector2f position);

    inline int get_return() const {return ret;}
    inline float get_width() const {return size.x;}
    inline float get_height() const {return size.y;}
};

#endif // BUTTON_H
