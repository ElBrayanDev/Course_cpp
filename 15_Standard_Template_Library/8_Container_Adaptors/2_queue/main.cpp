/*
*std::queue
#include <queue>

• First-in First-out (FIFO) data structure
• Implemented as an adapter over other STL container can be implemented as a list or deque
• Elements are pushed at the back and
popped from the front
• No iterators are supported

# Methods

• push() - insert an element at the back of the queue
! pop() - remove an element from the front of the queue
• front() - access the element at the front
• back() - access the element at the back
• empty() is the queue empty?
• size() - number of elements in the queue

# Initialization

std::queue<int> q; //! deque is default
std::queue<int, std::list<int>> q2;
std::queue<int, std::deque<int>> q3;
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

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

template <typename T>
void display(std::queue<T> q)
{
    cout << "[ ";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "]" << endl;
}

int main()
{
    std::queue<int> q;

    for (int i : {1, 2, 3, 4, 5})
        q.push(i);
    display(q);
    cout << "Front: " << q.front() << endl;
    cout << "Back:  " << q.back() << endl;

    q.push(100);
    display(q);

    q.pop();
    q.pop();
    display(q);

    while (!q.empty())
        q.pop();
    display(q);

    cout << "Size: " << q.size() << endl;

    q.push(10);
    q.push(100);
    q.push(1000);
    display(q);

    cout << "Front: " << q.front() << endl;
    cout << "Back:  " << q.back() << endl;

    q.front() = 5;
    q.back() = 5000;

    display(q);
    cout << "Front: " << q.front() << endl;
    cout << "Back:  " << q.back() << endl;

    return 0;
}