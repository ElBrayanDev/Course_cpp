/*
! Containers

• Data structures that can store object of almost any type
    • Template-based classes

• Each container has member functions
    • Some are specific to the container
    • Others are available to all containers

• Each container has an associated header file
    #include <container_type>

# Container elements
What types of elements can we store in containers?

• A copy of the element will be stored in the container
    • All primitives OK

• Element should be
    • Copyable and assignable (copy constructor / copy assignment)
    • Moveable for efficiency (move Constructor / move Assignment)

• Ordered associative containers must be able to compare elements
    • operator<, operator ==

! ITERATORS

• Allows abstracting an arbitrary container as a sequence of elements
• They are objects that work like pointers by design
• Most container classes can be traversed with iterators

# Declaring iterators
•Iterators must be declared based on the container type they will iterate over

#EX:    container_type::iterator_type iterator_name;

vector<int>::iterator itl;
std::list<string>::iterator it2;
std::map<string, string>::iterator it3;
std::set<char>::iterator it4;

=========================================================================================
#Initializing iterators

vector<int> vec {1,2,3};
vector<int>::iterator it = vec.begin();
or
! auto it = vec.begin();


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

#include <set>
#include <map>
#include <list>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// display any vector of integers using range-based for loop
void display(const vector<int> &vec)
{
    cout << "[ ";
    for (auto const &i : vec)
    {
        cout << i << " ";
    }
    cout << "]" << endl;
}

void test1()
{
    cout << "\n=============================" << endl;
    vector<int> nums1{1, 2, 3, 4, 5};
    auto it = nums1.begin(); // point to 1
    cout << *it << endl;

    it++; // point to 2
    cout << *it << endl;

    it += 2; // point to 4
    cout << *it << endl;

    it -= 2; // point to 2
    cout << *it << endl;

    it = nums1.end() - 1; // point to 5
    cout << *it << endl;
}

void test2()
{
    cout << "\n=============================" << endl;
    // display all vector elements using an iterator

    vector<int> nums1{1, 2, 3, 4, 5};

    vector<int>::iterator it = nums1.begin();
    while (it != nums1.end())
    {
        cout << *it << endl;
        it++;
    }

    // change all vector elements to 0
    it = nums1.begin();
    while (it != nums1.end())
    {
        *it = 0;
        it++;
    }

    display(nums1);
}

void test3()
{

    // using a const_iterator
    cout << "\n=============================" << endl;
    vector<int> nums1{1, 2, 3, 4, 5};

    vector<int>::const_iterator it1 = nums1.begin();
    // auto it1 = nums1.cbegin();

    while (it1 != nums1.end())
    {
        cout << *it1 << endl;
        it1++;
    }

    // compiler error when we try to change element
    it1 = nums1.begin();
    while (it1 != nums1.end())
    {
        // *it1 = 0;   // Complier error - read only
        it1++;
    }
}

void test4()
{
    // more iterators
    // using a reverse iterator
    vector<int> vec{1, 2, 3, 4};
    auto it1 = vec.rbegin(); // reverse iterator over vector of ints starts at 4
    while (it1 != vec.rend())
    {
        cout << *it1 << endl;
        it1++;
    }

    // const reverse iterator over a list
    std::list<string> name{"Larry", "Moe", "Curly"};
    auto it2 = name.crbegin(); // iterator over list of strings  point to Curly
    cout << *it2 << endl;
    it2++; // point to Moe
    cout << *it2 << endl;

    // iterator over a map
    std::map<string, string> favorites{
        {"Frank", "C++"},
        {"Bill", "Java"},
        {"James", "Haskell"}};
    auto it3 = favorites.begin(); // iterator over map of string, string pairs
    while (it3 != favorites.end())
    {
        cout << it3->first << " : " << it3->second << endl;
        it3++;
    }
}

void test5()
{
    // iterate over a subset of a container
    vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto start = vec.begin() + 2;
    auto finish = vec.end() - 3;

    while (start != finish)
    {
        cout << *start << endl;
        start++;
    }
}
int main()
{

    //    test1();
    //    test2();
    //    test3();
    //    test4();
    test5();
    return 0;
}