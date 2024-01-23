/*
#Algorithms

• STL algorithms work on sequences of container elements provided to them by an iterator

• STL has many common and useful algorithms

• Too many to describe in this section
    • http://en.cppreference.com/w/cpp/algorithm

• Many algorithms require extra information in order to do their work
    • Functors (function objects)
    • Function pointers
    • Lambda expressions (C++11)

#include <algorithm>

• Different containers support different types of iterators
    • Determines the types of algorithms supported

• All STL algorithms expect iterators as arguments
    • Determines the sequence obtained from the container

# Example algorithm - for_each

• for_each algorithm applies a function to each element in the iterator sequence

• Function must be provided to the algorithm as:
    • Functor (function object)
    • Function pointer
    • Lambda expression (C++11)

• Let's square each element

###########  EXAMPLE  ###########

for_each - using a lambda expression

std::vector<int> vec {1, 2, 3, 4};

std::for_each (vec.begin(), vec.end(),
    [] (int x) { std::cout << x * x << " "; }) // lambda
    1 4 9 16
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

#include <list>
#include <algorithm>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Person
{
    std::string name;
    int age;

public:
    Person() = default;
    Person(std::string name, int age)
        : name{name}, age{age} {}

    //! Important to overload comparition operators when using algorithms
    bool operator<(const Person &rhs) const
    {
        return this->age < rhs.age;
    }
    bool operator==(const Person &rhs) const
    {
        return (this->name == rhs.name && this->age == rhs.age);
    }
};

// Find an element in a container
void find_test()
{
    std::cout << "\n========================" << std::endl;

    std::vector<int> vec{1, 2, 3, 4, 5};

    auto loc = std::find(std::begin(vec), std::end(vec), 1); // # Another way of initializing Iterators

    if (loc != std::end(vec))
        std::cout << "Found the number: " << *loc << std::endl; // ! Derreference the iterator's pointer
    else
        std::cout << "Couldn't find the number" << std::endl;

    std::list<Person> players{
        {"Larry", 18},
        {"Moe", 20},
        {"Curly", 21}};

    auto loc1 = std::find(players.begin(), players.end(), Person{"Moe", 20}); // ? == overloaded
    if (loc1 != players.end())
        std::cout << "Found  Moe" << std::endl;
    else
        std::cout << "Moe not found" << std::endl;
}

// Count the number of elements in a container
void count_test()
{
    std::cout << "\n========================" << std::endl;

    std::vector<int> vec{1, 2, 3, 4, 5, 1, 2, 1};

    auto num = std::count(vec.begin(), vec.end(), 1);
    std::cout << num << " occurrences found" << std::endl;
}

// Count the number of occurences of an element in a container
// based on a predicate using a lambda expression
void count_if_test()
{
    std::cout << "\n========================" << std::endl;

    // count only if the element is even
    std::vector<int> vec{1, 2, 3, 4, 5, 1, 2, 1, 100};
    int num = std::count_if(vec.begin(), vec.end(), [](int x)
                            { return x % 2 == 0; }); // # boolean comparision that triggers the counter++
    std::cout << num << " even numbers found" << std::endl;

    num = std::count_if(vec.begin(), vec.end(), [](int x)
                        { return x % 2 != 0; }); // # boolean comparision that triggers the counter++
    std::cout << num << " odd numbers found" << std::endl;

    // how can we determine how many elements in vec are >= 5?
    num = std::count_if(vec.begin(), vec.end(), [](int x)
                        { return x >= 5; }); // # boolean comparision that triggers the counter++
    std::cout << num << "  numbers are >= 5" << std::endl;
}

// Replace occurrences of elements in a container
void replace_test()
{
    std::cout << "\n========================" << std::endl;

    std::vector<int> vec{1, 2, 3, 4, 5, 1, 2, 1};
    for (auto i : vec)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::replace(vec.begin(), vec.end(), 1, 100);
    for (auto i : vec)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void all_of_test()
{
    std::vector<int> vec1{1, 3, 5, 7, 9, 1, 3, 13, 19, 5};
    if (std::all_of(vec1.begin(), vec1.end(), [](int x)
                    { return x > 10; }))
        std::cout << "All the elements are > 10" << std::endl;
    else
        std::cout << "Not all the elements are > 10" << std::endl;

    if (std::all_of(vec1.begin(), vec1.end(), [](int x)
                    { return x < 20; }))
        std::cout << "All the elements are < 20" << std::endl;
    else
        std::cout << "Not all the elements are < 20" << std::endl;
}

// Transform elements in a container - string in this example
void string_transform_test()
{
    std::cout << "\n========================" << std::endl;

    std::string str1{"This is a test"};
    std::cout << "Before transform: " << str1 << std::endl;
    std::transform(str1.begin(), str1.end(), str1.begin(), ::toupper); // ? "::" for global scope
    std::cout << "After transform: " << str1 << std::endl;
}

int main()
{
    // find_test();
    // count_test();
    // count_if_test();
    // replace_test();
    // all_of_test();
    string_transform_test();

    return 0;
}