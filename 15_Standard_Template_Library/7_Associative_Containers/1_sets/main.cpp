/*
# The STL Set containers

* Associative containers
    • Collection of stored objects that allow fast retrieval using a key
    • STL provides Sets and Maps
    • Usually implemented as a balanced binary tree or hashsets
    • Most operations are very efficient

* Sets

• set
• std::unordered_set
• std::multiset
• std::unordered multiset

! set
#include <set>

• Similar to a mathematical set
• Ordered by key
• No duplicate elements
• All iterators available and invalidate when corresponding element is deleted

# Methods

! No .at(x) or [x]
? .insert() uses operator< for ordering
.find(x) returns iterator
.count(x) return times the element is on the set, 0 or 1
.clear()
.empty()

• returns a std::pair<iterator, bool>
    • first is an iterator to the inserted element or to the duplicate in the set
    • second is a boolean indicating success or failure

* std::multi_set
#include <set>
• Sorted by key
• Allows duplicate elements
• All iterators are available

* std:: unordered_set
#include <unordered_set>
• Elements are unordered
• No duplicate elements allowed
• Elements cannot be modified
• Must be erased and new element inserted
• No reverse iterators are allowed

* std: :unordered_multiset
#include <unordered_set>
• Elements are unordered
• Allows duplicate elements
• No reverse iterators are allowed
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

#include <set>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::set;
using std::string;
using std::vector;

class Person
{
    friend std::ostream &operator<<(std::ostream &os, const Person &p);
    string name;
    int age;

public:
    Person() : name{"Unknown"}, age{0} {}
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
    os << p.name << ": " << p.age;
    return os;
}

template <typename T>
void display(const set<T> &l)
{
    cout << "[ ";
    for (const auto &elem : l)
    {
        cout << elem << " ";
    }
    cout << "]" << endl;
}

void test1()
{
    // Sets
    cout << "\nTest1 =========================" << endl;
    set<int> s1{1, 4, 3, 5, 2};
    display(s1);

    s1 = {1, 2, 3, 1, 1, 2, 2, 3, 3, 4, 5};
    display(s1);

    s1.insert(0);
    s1.insert(10);

    display(s1);

    if (s1.count(10))
        cout << "10 is in the set" << endl;
    else
        cout << "10 is NOT in the set" << endl;

    auto it = s1.find(5);
    if (it != s1.end())
        cout << "Found: " << *it << endl;

    s1.clear();

    display(s1);
}

void test2()
{
    cout << "\nTest2 =========================" << endl;
    set<Person> stooges{
        {"Larry", 1},
        {"Moe", 2},
        {"Curly", 3}};
    display(stooges); //! Note the order of display!  operator<

    stooges.emplace("James", 50);
    display(stooges);

    stooges.emplace("Frank", 50); //! NO -- 50 already exists
    display(stooges);

    auto it = stooges.find(Person{"Moe", 2});
    if (it != stooges.end())
        stooges.erase(it);

    display(stooges);

    it = stooges.find(Person("XXXX", 50)); // Will remove James!!!!
                                           //! uses operator<
    if (it != stooges.end())
        stooges.erase(it);
    display(stooges);
}

void test3()
{
    cout << "\nTest3 =========================" << endl;

    set<string> s{"A", "B", "C"};
    display(s);

    auto result = s.insert("D");
    display(s);

    cout << std::boolalpha;
    cout << "first: " << *(result.first) << endl;
    cout << "second: " << result.second << endl;

    cout << endl;

    result = s.insert("A");
    display(s);

    cout << std::boolalpha;
    cout << "first: " << *(result.first) << endl;
    cout << "second: " << result.second << endl;
}

int main()
{
    test1();
    test2();
    test3();
    return 0;
}