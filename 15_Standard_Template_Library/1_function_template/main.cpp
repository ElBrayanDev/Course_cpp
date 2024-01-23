/*
# STL
• A library of powerful, reusable, adaptable, generic classes and functions
• Implemented using C++ templates
• Implements common data structures and algorithms
• Huge class library!!
• Alexander Stepanov (1994)

# Containers
   •Collections of objects or primitive types
    (array, vector, deque, stack, set, map, etc.)

•Algorithms
    • Functions for processing sequences of elements from containers
    (find, max, count, accumulate, sort, etc.)

•Iterators
    • Generate sequences of element from containers
    (forward, reverse, by value, by reference, constant, etc.)

# Types of Containers
 •Sequence containers
    • array, vector, list, forward_list, deque

•Associative containers
    •set, multi set, map, multi map

•Container adapters
    • stack, queue, priority queue

# Types of Iterators

    Input iterators - from the container to the program
    Output iterators - from the program to the container
    Forward iterators - navigate one item at a time in one direction
    Bi-directional iterators - navigate one item at a time both directions
    Random access iterators - directly access a container item

! Generic Programming with function templates
What is a C++ Template?
    • Blueprint
    • Function and class templates
    • Allow plugging-in any data type
    • Compiler generates the appropriate function/class from the blueprint
    • Generic programming / meta-programming

! template <typename T1, typename T2>


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

template <typename T>
T min(T a, T b)
{
    return (a < b) ? a : b;
}

template <typename T1, typename T2>
void func(T1 a, T2 b)
{
    cout << a << " " << b << endl;
}

struct Person
{
    string name;
    int age;
    bool operator<(const Person &rhs) const
    {
        return this->age < rhs.age;
    }
};

std::ostream &operator<<(std::ostream &os, const Person &p)
{
    os << p.name;
    return os;
}

template <typename T>
void my_swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

int main()
{
    int x{100};
    int y{200};
    cout << x << ", " << y << endl;
    my_swap(x, y);
    cout << x << ", " << y << endl;

    Person p1{"Curly", 15};
    Person p2{"Moe", 30};

    Person p3 = min(p1, p2);
    cout << p3.name << " is younger" << endl;

    func(p1, p2);

    cout << min<int>(2, 3) << endl;         // 2
    cout << min(2, 3) << endl;              // 2
    cout << min('A', 'B') << endl;          // A
    cout << min(12.5, 9.2) << endl;         // 9.2
    cout << min(5 + 2 * 2, 7 + 40) << endl; // 9

    func<int, int>(10, 20);
    func(10, 20);
    func<char, double>('A', 12.4);
    func('A', 12.4);
    func(1000, "Testing");
    func(2000, string{"Frank"});

    return 0;
}