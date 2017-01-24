/* ==========================================================================
   File: menu_button.cpp
   ========================================================================== */

#include "menu_button.hpp"

#include "defines.hpp"

menu_button::menu_button(std::string name,
                         int ret,
                         sf::Vector2f position,
                         sf::Vector2f size) :
ret(ret),
size(size),
text(name, FONT, 60),
background(size)
{
    text.setPosition(
        sf::Vector2f(position.x + (size.x / 2.0f -
                                   text.getLocalBounds().width / 2.0f),
                     position.y));
    background.setPosition(position);
    background.setFillColor(sf::Color(183, 0, 255));
}

bool menu_button::check_pressed(int x, int y)
{
    if (x >= background.getPosition().x &&
        x < background.getPosition().x + size.x &&
        y >= background.getPosition().y &&
        y < background.getPosition().y + size.y) {
        return true;
    }

    return false;
}

void menu_button::draw(sf::RenderWindow& window)
{
    window.draw(background);
    window.draw(text);
}

void menu_button::set_position(sf::Vector2f position)
{
    text.setPosition(
        sf::Vector2f(position.x + (size.x / 2.0f -
                                   text.getLocalBounds().width / 2.0f),
                     position.y));
    background.setPosition(position);
}
