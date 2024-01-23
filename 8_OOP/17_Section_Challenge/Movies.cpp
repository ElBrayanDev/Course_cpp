#include "Movies.h"
#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

Movies::Movies()
{
}

Movies::~Movies()
{
}

bool Movies::add_movie(std::string name, int rating, int watched_times)
{
    for (const Movie &m : movies) // # Keep it a const for each iteration
    {
        if (m.get_name() == name)
        {
            cout << "The movie: " << name << " is already included\n"
                 << endl;
            return false;
        }
    }
    Movie temp{name, rating, watched_times};
    movies.push_back(temp); // # pushback new movie to array list of movie obj
    cout << name << " was added" << endl;
    return true;
}
/// @brief gets a name of a movie, check if it exists
/// @param name
/// @return increments watched_times by 1
bool Movies::increment_watched(std::string name)
{
    for (auto &m : movies)
    {
        if (m.get_name() == name)
        {
            cout << name << " watch increment" << endl;
            m.increment_watched_times();
            return true;
        }
    }
    cout << "Movie: " << name << " doesn't exists" << endl;
    return false;
}

void Movies::display_all() const
{
    // #DO THIS
    if (movies.size() == 0)
    {
        cout << "You must have at least ONE movie added for being able to display them\n"
             << endl;
    }
    else
    {
        cout << "\nMovie(s) added\n"
             << endl;
        for (const auto &m : movies) // # const for m copy
        {

            m.display_data();
        }
    }
}