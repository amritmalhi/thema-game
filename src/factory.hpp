#ifndef FACTORY_H
/* ==========================================================================
   File: factory.hpp
   ========================================================================== */
#define FACTORY_H

#include <list>
#include <exception>
#include <string>

#include "drawable.hpp"

enum object_type {
    object_rectangle,
    object_line,
    object_circle,
    object_character,
    object_wall
};

class parse_exception : public std::exception
{
private:
    std::string msg;

public:
    parse_exception(std::string s)
    {
        msg = "Failed to parse: " + s;
    }

    virtual const char* what() const throw()
    {
        return msg.c_str();
    }
};

class unknown_shape : public std::exception
{
private:
    std::string msg;

public:
    unknown_shape(std::string s)
    {
        msg = "Unknown shape: " + s;
    }

    virtual const char* what() const throw()
    {
        return msg.c_str();
    }
};

class end_of_file : public std::exception
{
public:
    end_of_file()
    {

    }
};

drawable* load_object(std::ifstream& input, int& type);

#endif // FACTORY_H
