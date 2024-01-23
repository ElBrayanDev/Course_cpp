#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

string user_phrase;
string pyramid;
string pyramid_reversed;

int main()
{
    cout << "\nEnter a string for the pyramid: " << endl;
    getline(cin, user_phrase);

    /// @brief center first row
    for (char c : user_phrase)
    {
        cout << " ";
    }
    cout << " ";

    /// @brief with half pyramid row + pyramid reversed - the initial character
    /// @return gets you the full row of the pyramid, and gets it centered
    for (size_t i{0}; i < user_phrase.size(); i++)
    {
        pyramid += user_phrase.at(i); // gets you half the pyramid row
        pyramid_reversed = pyramid;
        reverse(pyramid_reversed.begin(), pyramid_reversed.end()); // inverse the pyramid row
        pyramid_reversed.erase(0, 1);                              // get rid of center char

        cout << pyramid << pyramid_reversed << endl; // print pyramid row, and its inversed one (without the starter char)

        for (size_t j{}; j < user_phrase.size() - i; j++)
        {
            cout << " "; // center the pyramid
        }
    }
    cout << endl;
    system("pause");
    return 0;
}