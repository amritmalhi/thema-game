#ifndef WINDOW_H
#define WINDOW_H

#include "SFML/Graphics.hpp"
#include "object.hpp"
#include "controllable.hpp"
#include "character.hpp"

///This clas expands the normal sf::renderWindow with a view port.
class window : public sf::RenderWindow{
private:
    sf::Vector2f window_size;
public:
    ///The constructor takes a window title and a window size.
    window(sf::String window_title, sf::Vector2f window_size);

    ///Sets the viewport to the target character provided.
    void set_target(character & target);

    ///Return viewport to the standard viewport.
    void no_target();

    ///For resizing the window.
    void resize();
};

#endif //WINDOW_H
