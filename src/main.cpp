#include <SFML/Graphics.hpp>
#include "drawable.hpp"
#include "rectangle.hpp"
#include "line.hpp"
#include "circle.hpp"

#include "level.hpp"

#define RES_LOC "../"

int main()
{
    level l = level(RES_LOC "res/level.txt");

    sf::RenderWindow window(sf::VideoMode(1600, 900), "SFML works!");

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }

        l.handle_input();

        window.clear();

        l.draw(window);

        window.display();
    }
    return 0;
}
