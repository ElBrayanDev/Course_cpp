#ifndef MOVIES_H
#define MOVIES_H

#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Movie.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Movies
{
private:
    vector<Movie> movies;

public:
    Movies();
    ~Movies();

    bool add_movie(string name, int rating, int watched_times);

    bool increment_watched(string name);

    void display_all() const;
};

#endif