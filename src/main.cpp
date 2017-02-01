#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>
#include "drawable.hpp"
#include "rectangle.hpp"
#include "line.hpp"
#include "circle.hpp"
#include <chrono>
#include "level.hpp"
#include <iostream>
#include "defines.hpp"
#include "window.hpp"
#include "level_manager.hpp"

#include "menu/main_menu.hpp"
#include "menu/pause_menu.hpp"
#include "menu/credits.hpp"

sf::Font FONT;

enum {
    STATE_MAIN_MENU,
    STATE_PAUSE_MENU,
    STATE_LEVEL,
    STATE_CREDITS
};

int main()
{
    int window_witdh = 1600;
    int window_height = 900;
    int state = STATE_MAIN_MENU;

    FONT.loadFromFile(RES_LOC "res/Android.ttf");
    level_manager lm;

    window window("thema game", sf::Vector2f(window_witdh, window_height));
    window.setFramerateLimit( FPS );

    // Create menus
    main_menu m = main_menu();
    pause_menu mp = pause_menu();
    credits cr = credits();

    auto lag = std::chrono::nanoseconds(0);
    auto elapsed = std::chrono::nanoseconds(0);

    auto previous = std::chrono::high_resolution_clock::now();
    auto current = std::chrono::high_resolution_clock::now();

    sf::Music soundtrack;

    if (!soundtrack.openFromFile("../res/sound.ogg")) {
            std::cout << "Music failed to load.";
    } else {
        soundtrack.setVolume(10);
        soundtrack.play();
        soundtrack.setLoop(true);
    }

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::Resized){
                window.resize();
                m.resize(event.size.width, event.size.height);
                mp.resize(event.size.width, event.size.height);
                cr.resize(event.size.width, event.size.height);
            }
            if (event.type == sf::Event::MouseMoved) {
                switch (state)
                {
                    case STATE_MAIN_MENU:
                        m.update_mouse_position(event.mouseMove.x,
                                                event.mouseMove.y);
                        break;
                    case STATE_PAUSE_MENU:
                        mp.update_mouse_position(event.mouseMove.x,
                                                 event.mouseMove.y);
                        break;
                }
            }
            if ((event.type == sf::Event::MouseButtonReleased &&
                 event.mouseButton.button == sf::Mouse::Left) ||
                (event.type == sf::Event::KeyReleased &&
                 event.key.code == sf::Keyboard::Return) ||
                (event.type == sf::Event::JoystickButtonReleased &&
                 event.joystickButton.button == 14)) {
                if (state == STATE_MAIN_MENU) {
                    int ret;
                    switch (event.type)
                    {
                        case sf::Event::MouseButtonReleased:
                            ret = m.handle_mouse_input(event.mouseButton.x,
                                                       event.mouseButton.y);
                            break;
                        case sf::Event::KeyReleased:
                        case sf::Event::JoystickButtonReleased:
                            ret = m.handle_button_input_execute();
                            break;
                    }

                    switch (ret)
                    {
                        case NEW_GAME:
                            lm.load_first_level();
                            state = STATE_LEVEL;
                            break;
                        case CREDITS:
                            state = STATE_CREDITS;
                            break;
                        case QUIT_GAME:
                            window.close();
                            break;
                    }
                } else if (state == STATE_PAUSE_MENU) {
                    int ret;
                    switch (event.type)
                    {
                        case sf::Event::MouseButtonReleased:
                            ret = mp.handle_mouse_input(event.mouseButton.x,
                                                        event.mouseButton.y);
                            break;
                        case sf::Event::KeyReleased:
                        case sf::Event::JoystickButtonReleased:
                            ret = mp.handle_button_input_execute();
                            break;
                    }

                    switch (ret)
                    {
                        case PAUSE_MENU_RESUME:
                            state = STATE_LEVEL;
                            break;
                        case PAUSE_MENU_BACK_TO_MAIN_MENU:
                            state = STATE_MAIN_MENU;
                            break;
                        case PAUSE_MENU_QUIT_GAME:
                            window.close();
                            break;
                    }
                }
            } else if (state == STATE_LEVEL &&
                       event.type == sf::Event::KeyReleased) {
                switch (event.key.code)
                {
                    case sf::Keyboard::Escape:
                        state = STATE_PAUSE_MENU;
                        break;
                    case sf::Keyboard::Q:
                        lm.get_level().next_controllables();
                        break;
                }
            } else if (state == STATE_LEVEL &&
                       event.type == sf::Event::JoystickButtonReleased) {
                switch (event.joystickButton.button)
                {
                    case 3:
                        state = STATE_PAUSE_MENU;
                        break;
                    case 11:
                    case 15:
                        lm.get_level().next_controllables();
                        break;
                }

            } else if (state == STATE_MAIN_MENU &&
                       event.type == sf::Event::KeyReleased) {
                switch(event.key.code)
                {
                    case sf::Keyboard::Up:
                        m.handle_button_input_previous();
                        break;
                    case sf::Keyboard::Down:
                        m.handle_button_input_next();
                        break;
                }
            } else if (state == STATE_MAIN_MENU &&
                       event.type == sf::Event::JoystickButtonReleased) {
                switch (event.joystickButton.button)
                {
                    case 4:
                        m.handle_button_input_previous();
                        break;
                    case 6:
                        m.handle_button_input_next();
                        break;
                }

            } else if (state == STATE_PAUSE_MENU &&
                       event.type == sf::Event::KeyReleased) {
                switch(event.key.code)
                {
                    case sf::Keyboard::Escape:
                        state = STATE_LEVEL;
                        break;
                    case sf::Keyboard::Up:
                        mp.handle_button_input_previous();
                        break;
                    case sf::Keyboard::Down:
                        mp.handle_button_input_next();
                        break;
                }
            } else if (state == STATE_PAUSE_MENU &&
                       event.type == sf::Event::JoystickButtonReleased) {
                switch (event.joystickButton.button)
                {
                    case 3:
                        state = STATE_LEVEL;
                        break;
                    case 4:
                        mp.handle_button_input_previous();
                        break;
                    case 6:
                        mp.handle_button_input_next();
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
                case STATE_PAUSE_MENU:
                    break;
                case STATE_LEVEL:
                    lm.get_level().handle_input();
                    lm.get_level().update();
                    lm.get_level().handle_collisions();
                    lm.get_paralax().update(
                        lm.get_level().get_current_target().get_position().x,
                        lm.get_level().get_current_target().get_position().y);

                    //Temporary way to get to the next level
                    if (lm.get_level().get_current_target().get_position().y > 1000) {
                        lm.next_level();
                    }
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
            case STATE_PAUSE_MENU:
                window.no_target();
                mp.draw(window);
                break;
            case STATE_LEVEL:
                window.set_target(lm.get_level().get_current_target());
                lm.get_paralax().draw(window);
                lm.get_level().draw(window);
                break;
            case STATE_CREDITS:
                window.no_target();
                cr.draw(window);
                if (cr.credits_finished()) {
                    state = STATE_MAIN_MENU;
                    cr = credits();
                }
                break;
        }

        window.display();
    }
    return 0;
}
