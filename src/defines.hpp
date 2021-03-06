#ifndef _DEFINES_HPP
#define _DEFINES_hpp

#include <SFML/Graphics/Font.hpp>

#include <chrono>

#define RES_LOC "../"
#define UPS 60
#define UPS_MS std::chrono::milliseconds( 1000/UPS )
#define FPS 60
#define FPS_MS std::chrono::milliseconds( 1000/FPS )

extern sf::Font FONT;

#endif //_DEFINES_hpp
