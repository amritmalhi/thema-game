#ifndef LEVEL_MANAGER_H
/* ==========================================================================
   File: level_manager.hpp
   ========================================================================== */
#define LEVEL_MANAGER_H

#include <vector>
#include <string>
#include <fstream>

#include <SFML/Graphics.hpp>

#include "level.hpp"
#include "paralax.hpp"

typedef struct {
    std::string level_name;
    std::string paralax_background;
} level_with_background;

class level_manager
{
private:
    int level_index;
    std::vector<level_with_background> level_list;
    level lvl;
    paralax par;

public:
    level_manager();

    void load_levels_from_file(std::string fname);
    void load_levels(std::ifstream& input);

    void load_first_level();
    void next_level();
    int get_index();
    void goto_level(int index);
    level& get_level();
    paralax& get_paralax();
};

#endif // LEVEL_MANAGER_H
