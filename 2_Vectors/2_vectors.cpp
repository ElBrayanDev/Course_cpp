/*
? Vectors, dynamic arrays, it can bound check.  .at(x) <---- This does the bound check
* Lot of cool functions with vectors, sort, reverse, find, etc.
! #include <vector>
!vector <int> test_scores;
todo vector <int> test_scores (10); // HAS A SIZE OF 10, and is already initialized to 0



*/

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

// using namespace std;

int main()
{
    // vector<int> test_scores(10); //! HAS A SIZE OF 10, and is already initialized to 0

    vector<char> vowels{'a', 'e', 'i', 'o', 'u'}; //* INITIALIZE the vectors value, with size of 5

    vector<double> temperatures(365, 80.5); //! First value (365) is the size of the arrangement, the second {80.5} is the value to initialize all the arrangement
    // test_scores.push_back(80); // todo .push_back(x) added 80 to the end of the vector, +1 element

    vector<int> test_scores{100, 95, 99};
    cout << "\nArray syntax: " << endl;
    cout << test_scores[0] << endl;
    cout << test_scores[1] << endl;
    cout << test_scores[2] << endl;

    cout << "\nVector syntax: " << endl;
    cout << test_scores.at(0) << endl;
    cout << test_scores.at(1) << endl;
    cout << test_scores.at(2) << endl;

    cout << "\nThere are: " << test_scores.size() << " scores in the vector" << endl;

    cout << " \nEnter one more score to the list: ";
    int score_added{0};
    cin >> score_added;
    test_scores.push_back(score_added);

    cout << "\nNew test scores are: " << endl;
    cout << test_scores.at(0) << endl;
    cout << test_scores.at(1) << endl;
    cout << test_scores.at(2) << endl;
    cout << test_scores.at(3) << endl;

    cout << "Now there are: " << test_scores.size() << " scores in the vector" << endl;

    // cout << test_scores.at(4) << endl;

    /*
    !Multidimentional vectors
    ? vector <vector<int>> movie_ratings
    !{
    ?  { 1, 2, 3, 4 },
    ?  { 1, 2, 4, 4 },
    ?  { 1, 3, 4, 5 },
    !};
     */

    vector<vector<int>> movie_ratings{{1, 2, 3, 4}, {1, 2, 4, 4}, {1, 3, 4, 5}};

    cout << "\nThis are the first row ratings: " << endl;
    cout << "#1: " << movie_ratings.at(0).at(0) << endl;
    cout << "#1: " << movie_ratings.at(0).at(1) << endl;
    cout << "#1: " << movie_ratings.at(0).at(2) << endl;
    cout << "#1: " << movie_ratings.at(0).at(3) << endl;

    return 0;
}