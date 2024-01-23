/*
# DEQUE
std::deque (double ended queue)
#include <deque>

• Dynamic size
    • Handled automatically
    • Can expand and contract as needed
    ! Elements are NOT stored in contiguous memory

• Direct element access (constant time)
! Rapid insertion and deletion at the front and back (constant time)
• Insertion or removal of elements (linear time)
• All iterators available and may invalidate

d.push_front(x);
d.size();
d.max_size();
d.at(x); - d[x];
d.front();
d.back();

d.push_back(x);
d.push_front(x);
d.pop_back();
d.pop_front();

d.emplace_back(obj);
d.emplace_front(obj);
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

#include <deque>
#include <algorithm>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

template <typename T>
void display(const std::deque<T> &d)
{
    cout << "[";
    for (const auto &elem : d)
        cout << elem << " ";
    cout << "]" << std::endl;
}

void test1()
{
    cout << "\nTest1 =========================" << std::endl;

    std::deque<int> d{1, 2, 3, 4, 5};
    display(d);

    d = {2, 4, 5, 6};
    display(d);

    std::deque<int> d1(10, 100); // ten 100s in the deque
    display(d1);

    d[0] = 100;
    d.at(1) = 200;
    display(d);
}

void test2()
{
    // push and pops
    cout << "\nTest2 =========================" << std::endl;

    std::deque<int> d{0, 0, 0};
    display(d);

    d.push_back(10);
    d.push_back(20);
    display(d);

    d.push_front(100);
    d.push_front(200);
    display(d);

    cout << "Front: " << d.front() << std::endl;
    cout << "Back : " << d.back() << std::endl;
    cout << "Size  : " << d.size() << std::endl;

    d.pop_back();
    d.pop_front();
    display(d);
}

// insert all even numbers into the back of a deque and all
// odd numbers into the front
void test3()
{
    cout << "\nTest3 =========================" << std::endl;

    vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::deque<int> d;

    for (const auto &elem : vec)
    {
        if (elem % 2 == 0)
            d.push_back(elem);
        else
            d.push_front(elem);
    }
    display(d);
}

void test4()
{
    // push front vs. back ordering
    cout << "\nTest4 =========================" << std::endl;

    vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::deque<int> d;

    for (const auto &elem : vec)
    {
        d.push_front(elem);
    }
    display(d);

    d.clear();

    for (const auto &elem : vec)
    {
        d.push_back(elem);
    }
    display(d);
}

void test5()
{
    // Same as test4 using std::copy
    cout << "\nTest5 =========================" << std::endl;

    vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::deque<int> d;

    std::copy(vec.begin(), vec.end(), std::front_inserter(d));
    display(d);

    d.clear();

    std::copy(vec.begin(), vec.end(), std::back_inserter(d));
    display(d);
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}