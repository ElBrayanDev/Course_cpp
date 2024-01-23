/*
# Challenge 1 - Deque Challenge

A Palindrome is a string that reads the same backwards or forwards.
Simple examples are:
madam
bob
toot
radar

An entire phrase can also be a palindome, for example:
A Toyota's a toyota
A Santa at NASA
A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!

For the purposes of this assignment we will only consider alpha characters and omit all other characters.
We will also not be considering case.
So,
A Santa at Nasa, will be processed as:
ASANTAATNASA

A common method to solve this problem is to compare the string to its reverse and
if the are equal then it must be a palindrome. But we will use a deque.

I am providing the main driver for you which will automatically run several test cases.
You challenge is to write the following function:

bool is_palindrome(const std::string &s) {

This function will expect a string and it must determine if that string is a palindrome and return true if it is, or false if it is not.

So,

is_palindrome("A Santa at Nasa");   will return true
is_palindrome("Hello");   will return false

Please use a deque to solve the problem.

If you need a hint, please as in the Q/A.
Good luck and have fun!
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
#include <deque>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

/// @brief checks if the passed string is a palindrome and returns a boolean
/// @param s string
/// @return boolean, true if the string is palindrome, otherwise false is returned
bool is_palindrome(const string &s)
{
    // ! Since we are learning the STL - use a deque to solve the problem.

    string str{s};
    std::deque<char> deq{};
    std::transform(str.begin(), str.end(), str.begin(), ::toupper); // string to upper

    std::copy_if(str.begin(), str.end(), std::back_inserter(deq), // copy if c is an alphabetic character
                 [](char c)
                 { return std::isalpha(c); });

    auto it = deq.begin();
    while (it != deq.end())
    {
        if (deq.front() == deq.back())
        {
            deq.pop_back();
            deq.pop_front();
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    vector<std::string> test_strings{"a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
                                     "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
                                     "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome"};

    cout << std::boolalpha;
    cout << std::setw(8) << std::left << "Result"
         << "String" << endl;
    for (const auto &s : test_strings)
    {
        cout << std::setw(8) << std::left << is_palindrome(s) << s << endl;
    }
    cout << endl;
    return 0;
}