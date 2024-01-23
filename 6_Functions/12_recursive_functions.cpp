/*  RECURSIVE FUNCTIONS

# A recursive function is a function that calls itself
    * Either directly or indirectly through another function

- Recursive problem solving
    + Base case
    + Divide the rest of problem into subproblem and do recursive call

- There are many problems that lend themselves to recursive solutions
# Mathematic - factorial, Fibonacci, fractals,...

- Searching and sorting - binary search, search trees, ...

- If recursion doesn't eventually stop you will have infinite recursion

- Recursion can be resource intensive

! Remember the base case(s)
    * It terminates the recursion

- Only use recursive solutions when it makes sense

Anything that can be done recursively can be done iteratively
! Stack overflow error

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

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

unsigned long long fibonacci(unsigned long long n);

unsigned long long fibonacci(unsigned long long n)
{
    if (n <= 1)
        return n; //! base case

    return fibonacci(n - 1) + fibonacci(n - 2); // recursion
}

int main()
{
    cout << fibonacci(5) << endl;  // 5
    cout << fibonacci(30) << endl; // 832040 
    cout << fibonacci(40) << endl; // 102334155
    return 0;
}