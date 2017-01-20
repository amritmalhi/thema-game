#include <SFML/Graphics.hpp>
#include "drawable.hpp"
#include "rectangle.hpp"
#include "line.hpp"
#include "circle.hpp"
#include <chrono>
#include "level.hpp"
#include <iostream>
#include "defines.hpp"

int main()
{
    level l = level(RES_LOC "res/level.txt");

    sf::RenderWindow window(sf::VideoMode(1600, 900), "SFML works!");
    window.setFramerateLimit( FPS );



    auto lag = std::chrono::nanoseconds(0);
    auto elapsed = std::chrono::nanoseconds(0);

    auto previous = std::chrono::high_resolution_clock::now();
    auto current = std::chrono::high_resolution_clock::now();

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }
        current = std::chrono::high_resolution_clock::now();
        elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(current - previous);
        previous = current;
        lag += elapsed;


        while ( lag >= UPS_MS )
        {
            l.handle_input();
            l.update();
            lag -= UPS_MS;
        }
        window.clear();
        l.draw(window);
        window.display();
    }
    return 0;
}
