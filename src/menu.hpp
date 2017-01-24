#ifndef MENU_H
/* ==========================================================================
   File: menu.hpp
   ========================================================================== */
#define MENU_H

#include <SFML/Graphics.hpp>

#include <vector>

#include "menu_button.hpp"

class menu
{
private:
    std::vector<menu_button> buttons;

protected:
    void add_button(std::string name,
                    int ret,
                    sf::Vector2f position = sf::Vector2f(0, 0));
    void draw_buttons(sf::RenderWindow& window);
    void center_buttons(int width, int height, int gap = 10);

public:
    int handle_input(int x, int y);
    virtual void draw(sf::RenderWindow& window) = 0;
    virtual void resize(int width, int height) = 0;
};

#endif // MENU_H
