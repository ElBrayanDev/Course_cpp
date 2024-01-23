/*
Challenge 4 - Stack and Queue Challenge

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
if the are equal then it must be a palindrome. But we will use a queue.

I am providing the main driver for you which will automatically run several test cases.
You challenge is to write the following function:

bool is_palindrome(const std::string &s) {

This function will expect a string and it must determine if that string is a palindrome and return true if it is, or false if it is not.

So,

is_palindrome("A Santa at Nasa");   will return true
is_palindrome("Hello");   will return false

Please use a stack and a queue to solve the problem.

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
#include <numeric>
#include <queue>
#include <stack>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::queue;
using std::stack;
using std::string;
using std::vector;

/// @brief checks if the passed string is a palindrome and returns a boolean
/// @param s string
/// @return boolean, true if the string is palindrome, otherwise false is returned
bool is_palindrome(const string &s)
{
    // ! Since we are learning the STL - use a queue and stack

    string str{s};
    std::queue<char> que{};
    std::stack<char> sta{};

    for (auto c : s)
    {
        if (std::isalpha(c))
        {
            que.push(toupper(c));
            sta.push(toupper(c));
        }
    }
    int size{(int)que.size()};

    for (int i{0}; i <= size / 2; i++)
    {
        if (que.front() == sta.top())
        {
            que.pop();
            sta.pop();
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
    std::vector<std::string> test_strings{"a", "abca", "aa", "aba", "abcba", "abba", "abbcbba", "ab", "abc", "radar", "bob",
                                          "ana", "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA",
                                          "C++", "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!",
                                          "This is a palindrome", "palindrome",
                                          "Red roses run no risk, sir, on Nurse’s order. ",
                                          "Now Ned, I am a maiden nun; Ned, I am a maiden won.",
                                          "Are we not drawn onward, we freer few, drawn onward to new era?"};

    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result"
              << "String" << std::endl;
    for (const auto &s : test_strings)
    {
        std::cout << std::setw(8) << std::left << is_palindrome(s) << s << std::endl;
    }
    std::cout << std::endl;
    return 0;
}