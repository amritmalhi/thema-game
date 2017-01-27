#include "physics.hpp"
#include <iostream>
/*///===============================================
  FILE:       physics.cpp
  AUTHOR:     Stefan de Beer
  DATE:       2017-01-20
/*///===============================================

#include "level_button.hpp"

physics::physics(sf::Vector2f position, sf::Vector2f size, object_type type):
collisionable(position, size, type),
previous_position(position)
{

}

bool physics::check_new_position(std::vector<collisionable*>& collisionables)
{
    for (auto& i : collisionables) {
        if (i != this) {
            if (detect_collision(*i)) {
				switch (i->get_object_type())
				{
				case object_level_button:
					((level_button*)i)->activate();
					break;
				}
                return true;
            }
        }
    }
    return false;
}
