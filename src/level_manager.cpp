/* ==========================================================================
   File: level_manager.cpp
   ========================================================================== */

#include "level_manager.hpp"

#include <iostream>

#include "factory.hpp"
#include "defines.hpp"

level_manager::level_manager() :
level_index(-1)
{
    load_levels_from_file(RES_LOC "res/levels.txt");
}

void level_manager::load_levels_from_file(std::string fname)
{
    try {
        std::ifstream file(fname);
        while (true)
        {
            try {
                load_levels(file);
            } catch (end_of_file& e) {
                break;
            }
        }
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void level_manager::load_levels(std::ifstream& input)
{
    std::string l, b;
    input >> l >> b;
    if (l == "" || b == "") {
        throw end_of_file();
    } else {
        level_list.push_back(level_with_background{l, b});
    }
}

void level_manager::load_first_level()
{
    if (level_list.size() < 1) {
        std::cout << "No level list!" << std::endl;
    }

    level_index = 0;
    lvl = level(RES_LOC "res/" + level_list[0].level_name);
    par.update_texture(RES_LOC "res/" + level_list[0].paralax_background);
}

void level_manager::next_level()
{
    level_index++;
    if (level_index >= level_list.size()) {
        return;
    }
    lvl = level(RES_LOC "res/" + level_list[level_index].level_name);
    par.update_texture(RES_LOC "res/" + level_list[level_index].paralax_background);
}

int level_manager::get_index()
{
    return level_index;
}

void level_manager::goto_level(int index)
{
    level_index = index;
    if (level_index >= level_list.size()) {
        return;
    }
    lvl = level(RES_LOC "res/" + level_list[level_index].level_name);
    par.update_texture(RES_LOC "res/" + level_list[level_index].paralax_background);
}

level& level_manager::get_level()
{
    return lvl;
}

paralax& level_manager::get_paralax()
{
    return par;
}
