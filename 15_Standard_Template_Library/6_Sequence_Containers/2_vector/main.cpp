/*
# VECTOR

vector
#include <vector>
• Dynamic size
    • Handled automatically
    • Can expand and contract as needed
    ! Elements are stored in contiguous memory as an array

• Direct element access (constant time)
! Rapid insertion and deletion at the back (constant time)
• Insertion or removal of elements (linear time)
• All iterators available and may invalidate

# Constructor

vector<int> vec1 {1, 2, 3, 4, 5};
vector<int> vec2 (10, 100);  **(size, fill_with)**

# Methods

vec.size(); vec.capacity();
vec.at(x);
vec[x];
vec.front();
vec.back();

vec.push_back(p1);  -  vec.pushback(Person{"Name", 18});  - //! vec.emplace_back("Brayan", 18);

vec.pop_back(); - remove the back element
vec.empty(); - boolean
vec.erase(vec.begin(), vec.begin());
vec.swap(vec2); - same type, can be different sizes
! vec.shrink_to_fit(); shrinks capacity to current size
vec.reserve(x); - sets capacity to x


# Using algorithms

// !std::back_inserter contructs a back-insert iterator that inserts new elements
    // at the end of the container it applied to. It's a special output iterator
    // It's awesome!!!!   and  very efficient
    // There is also a front_inserter we can use with deques and lists
    // Copy one list to another using an iterator and back_inserter

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

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Person
{
    friend std::ostream &operator<<(std::ostream &os, const Person &p);
    string name;
    int age;

public:
    Person() = default;
    Person(string name, int age)
        : name{name}, age{age} {}
    bool operator<(const Person &rhs) const
    {
        return this->age < rhs.age;
    }
    bool operator==(const Person &rhs) const
    {
        return (this->name == rhs.name && this->age == rhs.age);
    }
};

std::ostream &operator<<(std::ostream &os, const Person &p)
{
    os << p.name << ":" << p.age;
    return os;
}

// Use for_each and a lambda expression to display vector elements
void display2(const vector<int> &vec)
{
    cout << "[ ";
    std::for_each(vec.begin(), vec.end(),
                  [](int x)
                  { cout << x << " "; });
    cout << "]" << endl;
}

// template function to display any vector
template <typename T>
void display(const vector<T> &vec)
{
    cout << "[ ";
    for (const auto &elem : vec)
        cout << elem << " ";
    cout << "]" << endl;
}

void test1()
{
    cout << "\nTest1 =========================" << endl;

    vector<int> vec{1, 2, 3, 4, 5};
    display(vec);

    vec = {2, 4, 5, 6};
    display2(vec);

    vector<int> vec1(10, 100); // ten 100s in the vector
    display(vec1);
}

void test2()
{
    cout << "\nTest2 =========================" << endl;

    vector<int> vec{1, 2, 3, 4, 5};
    display(vec);
    cout << "\nvec size: " << vec.size() << endl;
    cout << "vec max size: " << vec.max_size() << endl;
    cout << "vec capacity: " << vec.capacity() << endl;

    vec.push_back(6);
    display(vec);
    cout << "\nvec size: " << vec.size() << endl;
    cout << "vec max size: " << vec.max_size() << endl;
    cout << "vec capacity: " << vec.capacity() << endl;

    vec.shrink_to_fit(); // C++11
    display(vec);
    cout << "\nvec size: " << vec.size() << endl;
    cout << "vec max size: " << vec.max_size() << endl;
    cout << "vec capacity: " << vec.capacity() << endl;

    vec.reserve(100);
    display(vec);
    cout << "\nvec size: " << vec.size() << endl;
    cout << "vec max size: " << vec.max_size() << endl;
    cout << "vec capacity: " << vec.capacity() << endl;
}

void test3()
{
    cout << "\nTest3 =========================" << endl;

    vector<int> vec{1, 2, 3, 4, 5};
    display(vec);

    vec[0] = 100;
    vec.at(1) = 200;

    display(vec);
}

void test4()
{
    cout << "\nTest4 =========================" << endl;
    vector<Person> stooges;

    Person p1{"Larry", 18};
    display(stooges);

    stooges.push_back(p1);
    display(stooges);

    stooges.push_back(Person{"Moe", 25});
    display(stooges);

    stooges.emplace_back("Curly", 30); // Use emplace_back!!!
    display(stooges);
}

void test5()
{
    cout << "\nTest5 =========================" << endl;

    vector<Person> stooges{
        {"Larry", 18},
        {"Moe", 25},
        {"Curly", 30}};

    display(stooges);
    cout << "\nFront: " << stooges.front() << endl;
    cout << "Back: " << stooges.back() << endl;

    stooges.pop_back();
    display(stooges);
}

void test6()
{
    cout << "\nTest6 =========================" << endl;
    vector<int> vec{1, 2, 3, 4, 5};
    display(vec);

    vec.clear(); // remove all elements
    display(vec);

    vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    display(vec);
    vec.erase(vec.begin(), vec.begin() + 2);
    display(vec);

    vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // erase all even numbers
    auto it = vec.begin();
    while (it != vec.end())
    {
        if (*it % 2 == 0)
            vec.erase(it);
        else
            it++; // only increment if not erased!
    }
    display(vec);
}

void test7()
{
    cout << "\nTest7 =========================" << endl;

    vector<int> vec1{1, 2, 3, 4, 5};
    vector<int> vec2{10, 20, 30, 40, 50};

    display(vec1);
    display(vec2);
    cout << endl;

    vec2.swap(vec1);
    display(vec1);
    display(vec2);
}

void test8()
{
    cout << "\nTest8  =========================" << endl;

    vector<int> vec1{1, 21, 3, 40, 12};

    display(vec1);
    std::sort(vec1.begin(), vec1.end());
    display(vec1);
}

void test9()
{
    // !std::back_inserter contructs a back-insert iterator that inserts new elements
    // at the end of the container it applied to. It's a special output iterator
    // It's awesome!!!!   and  very efficient
    // There is also a front_inserter we can use with deques and lists
    // Copy one list to another using an iterator and back_inserter

    cout << "\nTest9  =========================" << endl;

    vector<int> vec1{1, 2, 3, 4, 5};
    vector<int> vec2{10, 20};

    display(vec1);
    display(vec2);
    cout << endl;

    std::copy(vec1.begin(), vec1.end(), std::back_inserter(vec2));
    display(vec1);
    display(vec2);
    cout << endl;

    // # Copy_if the element is even

    vec1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vec2 = {10, 20};

    display(vec1);
    display(vec2);
    cout << endl;

    std::copy_if(vec1.begin(), vec1.end(), std::back_inserter(vec2),
                 [](int x)
                 { return x % 2 == 0; });
    display(vec1);
    display(vec2);
}

void test10()
{
    cout << "\nTest10  =========================" << endl;
    // # transform over 2 ranges

    vector<int> vec1{1, 2, 3, 4, 5};
    vector<int> vec2{10, 20, 30, 40, 50};
    vector<int> vec3;

    // 1*10, 2*20, 3*30, 4*40, 5*50 and store the results in vec3
    std::transform(vec1.begin(), vec1.end(), vec2.begin(),
                   std::back_inserter(vec3),
                   [](int x, int y)
                   { return x * y; });

    display(vec3);
}

// Insertion from another vector
// Insert vec2 into vec1 before the 5
void test11()
{
    cout << "\nTest11  =========================" << endl;
    vector<int> vec1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> vec2{100, 200, 300, 400};

    display(vec1);
    display(vec2);
    cout << endl;

    auto it = std::find(vec1.begin(), vec1.end(), 5);
    if (it != vec1.end())
    {
        cout << "inserting..." << endl;
        vec1.insert(it, vec2.begin(), vec2.end());
    }
    else
    {
        cout << "Sorry, 5 not found" << endl;
    }
    display(vec1);
}

int main()
{

    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
    test11();

    return 0;
}