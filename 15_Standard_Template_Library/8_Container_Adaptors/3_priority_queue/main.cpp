/*
* std::priority_queue
#include <queue>

• Allows insertions and removal of elements in order from the front of the container
• Elements are stored internally as a vector by default
• Elements are inserted in priority order
(largest value will always be at the front)
• No iterators are supported

• push() - insert an element into sorted order
• pop() - removes the top element (greatest)
• top() - access the top element (greatest)
• empty() is the queue empty?
• size() - number of elements in the queue
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
        // return this->age < rhs.age;
        return this->name < rhs.name;
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

// This displays the priority queue by
// repeatedly topping and popping the priority queue
// It is being passed by value so we don't modify the
// priority queue being passed in
template <typename T>
void display(std::priority_queue<T> pq)
{
    cout << "[ ";
    while (!pq.empty())
    {
        T elem = pq.top();
        pq.pop();
        cout << elem << " ";
    }
    cout << "]" << endl;
}

void test1()
{
    cout << "\nTest1 =========================" << endl;

    std::priority_queue<int> pq;
    for (int i : {3, 5, 7, 12, 23, 12, 4, 100, 0, 3, 5, 7})
        pq.push(i);

    cout << "Size: " << pq.size() << endl;
    cout << "Top: " << pq.top() << endl;

    display(pq);

    pq.pop();
    display(pq);
}

void test2()
{
    cout << "\nTest2 =========================" << endl;

    std::priority_queue<Person> pq;
    pq.push(Person{"A", 10});
    pq.push(Person{"B", 1});
    pq.push(Person{"C", 14});
    pq.push(Person{"D", 18});
    pq.push(Person{"E", 7});
    pq.push(Person{"F", 27});

    display(pq);
}

int main()
{
    test1();
    test2();
    return 0;
}