#include <SFML/Graphics.hpp>
#include "drawable.hpp"
#include "rectangle.hpp"
#include "line.hpp"
#include "circle.hpp"
#include <chrono>
#include "level.hpp"
#include <iostream>
#include "defines.hpp"
#include "window.hpp"

#include "menu_main.hpp"

sf::Font FONT;

enum {
    STATE_MAIN_MENU,
    STATE_LEVEL
};

int main()
{
    int window_witdh = 1600;
    int window_height = 900;
    int state = STATE_MAIN_MENU;

    FONT.loadFromFile(RES_LOC "res/Android.ttf");
    level l = level(RES_LOC "res/level.txt");

    window window("thema game", sf::Vector2f(window_witdh, window_height));
    window.setFramerateLimit( FPS );

    menu_main m = menu_main();

    auto lag = std::chrono::nanoseconds(0);
    auto elapsed = std::chrono::nanoseconds(0);

    auto previous = std::chrono::high_resolution_clock::now();
    auto current = std::chrono::high_resolution_clock::now();


    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::Resized){
                window.resize();
                m.resize(event.size.width, event.size.height);
            }
            if (event.type == sf::Event::MouseButtonReleased &&
                event.mouseButton.button == sf::Mouse::Left) {
                int ret = m.handle_input(event.mouseButton.x,
                                         event.mouseButton.y);
                switch (ret)
                {
                    case NEW_GAME:
                        l = level(RES_LOC "res/level.txt");
                        state = STATE_LEVEL;
                        break;
                    case QUIT_GAME:
                        window.close();
                        break;
                }
            }
        }
        current = std::chrono::high_resolution_clock::now();
        elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(current - previous);
        previous = current;
        lag += elapsed;


        while ( lag >= UPS_MS )
        {
            switch (state)
            {
                case STATE_MAIN_MENU:
                    break;
                case STATE_LEVEL:
                    l.handle_input();
                    l.update();
                    break;
            }

            lag -= UPS_MS;
        }

        window.clear();

        switch (state)
        {
            case STATE_MAIN_MENU:
                window.no_target();
                m.draw(window);
                break;
            case STATE_LEVEL:
                window.set_target(l.get_current_target());
                l.draw(window);
                break;
        }

        window.display();
    }
    return 0;
}
