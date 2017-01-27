#ifndef CREDITS_H
/* ==========================================================================
   File: credits.hpp
   ========================================================================== */
#define CREDITS_H

#include "menu.hpp"

#include <vector>

class credits : public menu
{
private:
    std::vector<sf::Text> credit_text;
    int window_height;

public:
    credits();

    void draw(sf::RenderWindow& window);
    void resize(int width, int height);

    bool credits_finished();
};

#endif // CREDITS_H
