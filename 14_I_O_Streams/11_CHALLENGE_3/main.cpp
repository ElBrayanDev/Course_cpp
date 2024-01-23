/*
#Word finder

Ask the user to enter a word
Process the Romeo and Juliet file and determine how many total words there are
and how many times the word the user entered appears as a substring of a word in the play.

For example.
If the user enters: love
Then the words love, lovely, and beloved will all be considered matches.
You decide whether you want to be case sensitive or not. My solution is case sensitive

Sample are some sample runs:

Enter the substring to search for: love
25919 words were searched...
The substring love was found 171 times

Enter the substring to search for: Romeo
25919 words were searched...
The substring Romeo was found 132 times

Enter the substring to search for: Juliet
25919 words were searched...
The substring Juliet was found 49 times

Enter the substring to search for: Frank
25919 words were searched...
The substring Frank was found 0 times

Have fun!
*/

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <cctype>
#include <string>
#include <vector>
#include <cmath>
#include <memory>
#include <fstream>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    string find{};
    string word{};
    int word_counter{0};
    int matches{0};
    std::ifstream reader;

    reader.open("romeoandjuliet.txt");

    if (!reader)
    {
        cerr << "'romeoandjuliet.txt' wasn't found" << endl;
    }
    cout << endl
         << "Enter the substring to search for: ";
    cin >> find;

    while (reader >> word)
    {
        word_counter++;
        if (word.contains(find))
        {
            matches++;
        }
    }

    cout << endl
         << word_counter << " words were searched..." << endl
         << "The substring " << find << " was found " << matches << " times" << endl;

    return 0;
}