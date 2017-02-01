#ifndef LEVEL_H
/* ==========================================================================
   File: level.hpp
   ========================================================================== */
#define LEVEL_H

/**
 * @file level.hpp
 * @brief Contains the level class
 */

#include <memory>
#include <vector>
#include <string>

#include <SFML/Graphics.hpp>

#include "drawable.hpp"
#include "controllable.hpp"
#include "collisionable.hpp"
#include "physics.hpp"
#include "view_port.hpp"
#include "character.hpp"

/// The level class that holds all the objects inside the level together
class level
{
private:
    /// A list of all the drawables in the level
    std::vector<std::shared_ptr<drawable>> drawables;

    /// A list of all the controllables in the level
    std::vector<controllable*> controllables;

    /// A list of all the collisionables in the level
    std::vector<collisionable*> collisionables;

    /// A list of all the physics objects in the level
    std::vector<physics*> physics_objects;

    /// A list of all the trackables in the level
    std::vector<character*> trackables;

    /// A list of all the loaded textures
	std::map<std::string, sf::Texture> textures;

    /// The index of the current active trackable
    unsigned int current_trackable = 0;

public:
    /**
     * @brief Creates a new empty level object
     */
    level();

    /**
     * @brief Creates a new level object from a level file
     * @param fname The file name of the level file
     */
    level(std::string fname);

    /**
     * @brief Cleans up the level from memory
     */
    ~level();

    /**
     * @brief Draws the level on the window
     * @param window The window to draw the level on
     */
    void draw(sf::RenderWindow& window);

    /**
     * @brief Lets the current trackable handle the user input
     */
    void handle_input();

    /**
     * @brief Sends all the physics object an update tick
     */
    void update();

    /**
     * @brief Loads a level from a level file
     * @param fname The file name to load the level from
     */
    void load_level_from_file(std::string fname);

    /**
     * @brief Handles collisions
     */
    void handle_collisions();

    /**
     * @brief Selects the next controllable
     */
    void next_controllables();

    /**
     * @brief Gets the current target that is controlled
     * @return The current trackable that is selected
     */
    character& get_current_target();
};

#endif // LEVEL_H
