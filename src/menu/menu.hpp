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
    int selected_button = -1;

protected:
    void add_button(std::string name,
                    int ret,
                    sf::Vector2f position = sf::Vector2f(0, 0));
    void draw_buttons(sf::RenderWindow& window);
    void center_buttons(int width, int height, int gap = 10);

public:
    int handle_mouse_input(int x, int y);
    void update_mouse_position(int x, int y);
    void handle_button_input_next();
    void handle_button_input_previous();
    int handle_button_input_execute();
    virtual void draw(sf::RenderWindow& window) = 0;
    virtual void resize(int width, int height) = 0;
};

#endif // MENU_H
