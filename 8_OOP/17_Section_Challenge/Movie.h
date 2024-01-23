#ifndef MOVIE_H
#define MOVIE_H

#pragma once
#include <string>

/*
MODELS a Movie
*/

class Movie
{
private:
    std::string name;
    int rating;
    int watched_times;

public:
    //# Ctor
    Movie(std::string name = "None", int rating = 0, int watched_times = 0);

    //# Copy Ctor
    Movie(const Movie &source);

    //# Destructor
    ~Movie();

    //# methods
    void set_name(std::string name) { this->name = name; }
    std::string get_name() const { return name; }

    void set_rating(int rating) { this->rating = rating; }
    int get_rating() const { return rating; }

    void set_watched_times(int watched_times) { this->watched_times = watched_times; }
    int get_watched_times() const { return watched_times; }

    //# Increment
    void increment_watched_times() { ++watched_times; }

    //# Display method
    void display_data() const;
};

#endif