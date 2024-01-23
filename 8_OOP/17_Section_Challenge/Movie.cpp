#include "Movie.h"
#include <iostream>

/* IMPLEMENTATION OF THE CONSTRUCTOR
 */

Movie::Movie(std::string name, int rating, int watched_times)
    : name(name), rating(rating), watched_times(watched_times)
{
}

//# Implementation Copy Ctor
Movie::Movie(const Movie &source)
    : Movie{source.name, source.rating, source.watched_times}
{
}

//# Implementation Destructor
Movie::~Movie()
{
}

//# Implementation Display Method

// @brief Returns all data of the Movie object

void Movie::display_data() const
{
    std::cout << "Name: " << name << " | Rating: " << rating << " | Times watched: " << watched_times << std::endl;
}