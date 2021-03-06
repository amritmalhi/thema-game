/* ==========================================================================
   File: menu.cpp
   ========================================================================== */

#include "menu.hpp"

void menu::add_button(std::string name, int ret, sf::Vector2f position)
{
    if (position == sf::Vector2f(0, 0)) {
        position = sf::Vector2f(0, buttons.size() * 80);
    }
    buttons.push_back(menu_button(name, ret, position));
}

void menu::draw_buttons(sf::RenderWindow& window)
{
    for (auto& i : buttons) {
        i.draw(window);
    }
}

void menu::center_buttons(int width, int height, int gap)
{
    if (buttons.size() == 0) {
        return;
    }

    float total_height = 0;
    for (auto& i : buttons) {
        total_height += i.get_height();
        total_height += gap;
    }
    total_height -= gap;

    float x = width / 2.0f;
    float y = height / 2.0f - total_height / 2.0f;

    for (auto& i : buttons) {
        i.set_position(sf::Vector2f(x - i.get_width() / 2.0f, y));
        y += i.get_height();
        y += gap;
    }
}

int menu::handle_mouse_input(int x, int y)
{
    for (auto& i : buttons) {
        if (i.check_location(x, y)) {
            return i.get_return();
        }
    }
    return -1;
}

void menu::update_mouse_position(int x, int y)
{
    selected_button = -1;

    for (auto& i : buttons) {
        if (i.check_location(x, y)) {
            i.set_active(true);
        } else {
            i.set_active(false);
        }
    }
}

void menu::handle_button_input_next()
{
    if (selected_button < 0) {
        selected_button = 0;
    } else {
        buttons[selected_button].set_active(false);
        selected_button++;
    }
    selected_button = selected_button % buttons.size();
    buttons[selected_button].set_active(true);
}

void menu::handle_button_input_previous()
{
    if (selected_button < 0) {
        selected_button = buttons.size() - 1;
    } else {
        buttons[selected_button].set_active(false);
        selected_button--;
        if (selected_button < 0) {
            selected_button = buttons.size() - 1;
        }
    }
    selected_button = selected_button % buttons.size();
    buttons[selected_button].set_active(true);
}

int menu::handle_button_input_execute()
{
    if (selected_button < 0) {
        return -1;
    }
    return buttons[selected_button].get_return();
}
