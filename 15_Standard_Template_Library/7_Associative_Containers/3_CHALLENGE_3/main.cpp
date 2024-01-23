/*
Section 20
Challenge 3
Using set and map

This challenge has 2 parts.
We will be reading words from a text file provided to you.
The text file is named 'words.txt' and contains the fist few
paragraphs from the book, "The Wonderful Wizard of Oz", by
L. Frank Baum.

Part 1:

For part 1 of this challenge, you are to display each unique word
in the file and immediately following each word display the number
of time it occurs in the text file.

The words should be displayed in ascending order.

Here is a sample listing of the first few words:

Word         Count
===================
Aunt           5
Dorothy        8
Dorothy's      1
Em             5
Even           1
From           1

Please use a map with <string, int> Key/ Value pairs

============================================
Part 2:

For part 2 of this challenge, you are to display each unique word
in the file and immediately following each word display the line numbers
in which that word appears.

The words should be displayed in ascending order and the line numbers for
each word should also be displayed in ascending order.
If a word appears more than once on a line then the line number should
only appear once.

Here is a sample listing of the first few words:

Word                Occurrences
=========================================
Aunt          [ 2 7 25 29 48 ]
Dorothy       [ 1 7 15 29 39 43 47 51 ]
Dorothy's     [ 31 ]
Em            [ 2 7 25 30 48 ]
Even          [ 19 ]
From          [ 50 ]

Please use a map of <string,set<int>> Key/Value pairs

Hint: consider using stringstream to process words
once you read in a line from the file.

Note: I have provided the basic shell for your program.
I have also provided the functions that display the maps
as well as the function that cleans the words read.
You should call the clean_string function for every word
you read from the file.

Good luck and have fun!!!
Don't over think this one -- use the STL!
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
#include <algorithm>
#include <numeric>

#include <map>
#include <set>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::set;
using std::string;
using std::vector;

// Used for Part1
// Display the word and count from the
// map<string, int>

void display_words(const map<string, int> &words)
{
    cout << std::setw(12) << std::left << "\nWord"
         << std::setw(7) << std::right << "Count" << endl;
    cout << "===================" << endl;
    for (auto pair : words)
        cout << std::setw(12) << std::left << pair.first
             << std::setw(7) << std::right << pair.second << endl;
}

// Used for Part2
// Display the word and occurences from the
// map<string, set<int>>

void display_words(const map<string, set<int>> &words)
{
    cout << std::setw(12) << std::left << "\nWord"
         << "Occurrences" << endl;
    cout << "=====================================================================" << endl;
    for (auto pair : words)
    {
        cout << std::setw(12) << std::left << pair.first
             << std::left << "[ ";
        for (auto i : pair.second)
            cout << i << " ";
        cout << "]" << endl;
    }
}

// This function removes periods, commas, semicolons and colon in
// a string and returns the clean version
string clean_string(const string &s)
{
    string result;
    for (char c : s)
    {
        if (c == '.' || c == ',' || c == ';' || c == ':')
        {
            continue;
        }
        else
        {
            c = toupper(c);
            result += c;
        }
    }
    return result;
}

// Part1 process the file and builds a map of words and the
// number of times they occur in the file

int part1()
{
    map<string, int> words;
    string line;
    string word;
    std::ifstream reader{"words.txt"};

    if (!reader)
    {
        std::cerr << "Error opening input file" << endl;
        return -1;
    }

    while (reader >> word)
    {
        word = clean_string(word);
        words[word]++; //! increments the int counter for word appeareances
    }

    reader.close();
    display_words(words);
    return 0;
}

// Part2 process the file and builds a map of words and a
// set of line numbers in which the word appears
int part2()
{
    map<string, set<int>> words;
    string line;
    string word;
    std::ifstream reader{"words.txt"};

    if (!reader)
    {
        std::cerr << "Error opening input file" << endl;
        return -1;
    }

    int line_counter{0};
    while (std::getline(reader, line))
    {
        line_counter++;
        std::stringstream ss(line);
        while (ss >> word)
        {
            word = clean_string(word);
            words[word].insert(line_counter); //! insert the line where this word appears on the word.second (set)
        }
    }

    reader.close();
    display_words(words);
    return 0;
}

int main()
{
    part1();
    part2();
    return 0;
}