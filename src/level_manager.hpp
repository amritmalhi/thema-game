#ifndef LEVEL_MANAGER_H
/* ==========================================================================
   File: level_manager.hpp
   ========================================================================== */
#define LEVEL_MANAGER_H

/**
 * @file level_manager.hpp
 * @brief Contains the level manager class
 */

#include <vector>
#include <string>
#include <fstream>

#include <SFML/Graphics.hpp>

#include "level.hpp"
#include "paralax.hpp"

/// Bundles the level name and corresponding paralax background together
typedef struct {
    std::string level_name;
    std::string paralax_background;
} level_with_background;

/// Keeps track of levels and paralax backgrounds
class level_manager
{
private:
    /// Contains the index of the current level in the list
    int level_index;

    /// The list of all the levels with their background
    std::vector<level_with_background> level_list;

    /// The currently loaded level
    level lvl;

    /// The currently loaded paralax
    paralax par;

public:
    /**
     * @brief Creates a new level manager object
     */
    level_manager();

    /**
     * @brief Loads a level list from a file
     * @param fname The filename to load the level list from
     */
    void load_levels_from_file(std::string fname);

    /**
     * @brief Loads a level list form an input stream
     * @param input The input stream to load it from
     */
    void load_levels(std::ifstream& input);

    /**
     * @brief Loads the first level from the level list as current actively
     * loaded level
     */
    void load_first_level();

    /**
     * @brief Loads the next level in the list as current active level
     */
    void next_level();

    /**
     * @brief Returns the index of the current level in the list
     * @return The index of the current level
     */
    int get_index();

    /**
     * @brief Loads a specific index in the level list
     * @param index The level to load
     */
    void goto_level(int index);

    /**
     * @brief Returns the current active level
     * @return The currently loaded level
     */
    level& get_level();

    /**
     * @brief Returns the current active paralax
     * @return The current paralax background
     */
    paralax& get_paralax();
};

#endif // LEVEL_MANAGER_H
