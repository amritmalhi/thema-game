#ifndef FACTORY_H
/* ==========================================================================
   File: factory.hpp
   ========================================================================== */
#define FACTORY_H

/**
 * @file factory.hpp
 * @brief Contains the factory function and factory exceptions
 */

#include <list>
#include <exception>
#include <string>

#include "drawable.hpp"

/// The exception thrown when the factory can't parse something
class parse_exception : public std::exception
{
private:
    /// The exception message
    std::string msg;

public:
    /**
     * @brief Creates a new parse exception
     * @param s The parse error
     */
    parse_exception(std::string s)
    {
        msg = "Failed to parse: " + s;
    }

    /**
     * @brief Returns the exception message
     * @return The exception message
     */
    virtual const char* what() const throw()
    {
        return msg.c_str();
    }
};

/// The exception thrown when the factory found an unknown shape
class unknown_shape : public std::exception
{
private:
    /// The exception message
    std::string msg;

public:
    /**
     * @brief Creates a new unknown shape exception
     * @param s The shape that is unknown
     */
    unknown_shape(std::string s)
    {
        msg = "Unknown shape: " + s;
    }

    /**
     * @brief Returns the exception message
     * @return The exception message
     */
    virtual const char* what() const throw()
    {
        return msg.c_str();
    }
};

/// The exception thrown when the factory reaches the end of the file
class end_of_file : public std::exception
{
public:
    /**
     * @brief Creates a new end of file exception
     */
    end_of_file()
    {

    }
};

/**
 * @brief Loads the next object from the input stream
 * @param input The input stream to parse the next object from
 * @param type Is set to the type of object that was parsed
 * @param textures The list of textures already loaded to not load textures
 * double
 * @return Returns an drawable pointer to the newly created object
 */
drawable* load_object(std::ifstream& input, int& type, std::map<std::string, sf::Texture> & textures);

#endif // FACTORY_H
