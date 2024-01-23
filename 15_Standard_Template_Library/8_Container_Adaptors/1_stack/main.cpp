/*
* stack
#include <stack>
• Last-in First-out (LIFO) data structure
• Implemented as an adapter over other STL container
    Can be implemented as a vector, list, or deque
• All operations occur on one end of the stack (top)
! No iterators are supported

# Methods

• push() - insert an element at the top of the stack
• pop() - remove an element from the top of the stack
• top() - access the top element of the stack
• empty() is the stack empty?
• size() - number of elements in the stack

# Initialization
stack<int> s;
stack<int, vector<int>> sl;
stack<int, list<int>> s2;
stack<int, std::deque<int>> s3;

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
#include <list>
#include <stack>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::stack;
using std::string;
using std::vector;

template <typename T>
void display(stack<T> s)
{
    cout << "[ ";
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "]" << endl;
}

int main()
{
    stack<int> s;
    stack<int, vector<int>> s1;
    stack<int, list<int>> s2;
    stack<int, std::deque<int>> s3;

    for (int i : {1, 2, 3, 4, 5})
        s.push(i);
    display(s);

    s.push(100);
    display(s);

    s.pop();
    s.pop();
    display(s);

    while (!s.empty()) //! .clear() for stack
        s.pop();
    display(s);

    cout << "Size: " << s.size() << endl;

    s.push(10);
    display(s);

    s.top() = 100; //! assigns a value to the top
    display(s);
    return 0;
}