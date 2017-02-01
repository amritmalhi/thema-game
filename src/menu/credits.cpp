/* ==========================================================================
   File: credits.cpp
   ========================================================================== */

#include "credits.hpp"

#include "../defines.hpp"

credits::credits() :
window_height(900)
{
    credit_text.push_back(sf::Text("Programmers:", FONT, 50));
    credit_text.push_back(sf::Text("Stefan de Beer", FONT, 50));
    credit_text.push_back(sf::Text("Paul Ettema", FONT, 50));
    credit_text.push_back(sf::Text("Jeroen Kok", FONT, 50));
    credit_text.push_back(sf::Text("Brian Duncker", FONT, 50));
    credit_text.push_back(sf::Text("Bart van der Kolk", FONT, 50));
    credit_text.push_back(sf::Text("Amrit Malhi", FONT, 50));

    int x = 1600 / 2;
    int y = 900;
    for (auto& i : credit_text)
    {
        i.setPosition(sf::Vector2f(x - i.getLocalBounds().width / 2.0f, y));
        y += 70;
    }
}

void credits::draw(sf::RenderWindow& window)
{
    for (auto& i : credit_text)
    {
        window.draw(i);
        i.move(0, -1.5f);
    }
}

void credits::resize(int width, int height)
{
    int x = width / 2;
    for (auto& i : credit_text)
    {
        i.setPosition(sf::Vector2f(x - i.getLocalBounds().width / 2.0f,
                                   i.getPosition().y - window_height + height));
    }
    window_height = height;
}

bool credits::credits_finished()
{
    if (credit_text[credit_text.size() - 1].getPosition().y < - 70) {
        return true;
    }
    return false;
}
