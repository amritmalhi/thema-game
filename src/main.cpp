#include <SFML/Graphics.hpp>
#include "drawable.hpp"
#include "rectangle.hpp"
#include "line.hpp"

int main()
{
  
  sf::RenderWindow window(sf::VideoMode(1600, 900), "SFML works!");
  rectangle shape1(sf::Vector2f(100, 100), sf::Vector2f(100, 100));
  line shape2(sf::Vector2f(200, 200), sf::Vector2f(300, 5), 45);
  drawable * shapes[] = {&shape1, &shape2};
  
  while (window.isOpen()){
    sf::Event event;
    while (window.pollEvent(event)){
      if (event.type == sf::Event::Closed)
	window.close();
    } 
    window.clear();
    for(auto & i : shapes){
      i->draw(window);
    }
    window.display();
  }
  return 0;
}