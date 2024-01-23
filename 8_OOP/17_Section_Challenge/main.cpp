#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include "Movies.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    Movies my_movies;

    my_movies.display_all();

    my_movies.add_movie("Big", 10, 2);       // OK
    my_movies.add_movie("Star Wars", 5, 5);  // OK
    my_movies.add_movie("Cinderella", 4, 7); // OK

    my_movies.display_all(); // Big, Star Wars, Cinderella

    my_movies.add_movie("Cinderella", 3, 7); // Already exists
    my_movies.add_movie("Ice Age", 1, 12);   // OK

    my_movies.display_all(); // Big, Star Wars, Cinderella, Ice Age

    my_movies.increment_watched("Big");     // OK
    my_movies.increment_watched("Ice Age"); // OK

    my_movies.display_all(); // Big and Ice Age watched count incremented by 1

    my_movies.increment_watched("XXX"); // XXX not found

    return 0;
}
