/*
# The STL Map containers

• Associative
    •containers
    • Collection of stored objects that allow fast retrieval using a key
    • STL provides Sets and Maps
        • Usually implemented as a balanced binary tree or hashsets
        • Most operations are very efficient

• Maps
    • map
    • std::unordered_map
    • std::multimap
    • std:: unordered_multimap

* map
#include <map>
• Similar to a dictionary
• Elements are stored as Key, Value pairs (std::pair)
• Ordered by key
• No duplicate elements (keys are unique)
• Direct element access using the key
• All iterators available and invalidate when corresponding element is deleted

# Methods

paired objects
m.insert(obj); - m.insert(std::make_pair("Brayan", "Barrera"));

m["Frank"] = "Teacher"; // insert

m["Frank"] = "Instructor"; // update value

m.at ("Frank") = "Professor"; // update value

m.count(obj); // 0 or 1
m.clear();
m.empty();

* std::multi_map
#include <map>
• Ordered by key
• Allows duplicate elements
• All iterators are available

* std:: unordered_map
#include <unordered_map>
• Elements are unordered
• No duplicate elements allowed
• No reverse iterators are allowed

* std:: unordered_multimap
#include <unordered_map>
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
#include <map>
#include <set>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;

void display(const map<string, std::set<int>> &m)
{
    cout << "[ ";
    for (const auto &elem : m)
    {
        cout << elem.first << ": [ ";
        for (const auto &set_elem : elem.second)
            cout << set_elem << " ";
        cout << "] ";
    }
    cout << "]  " << endl;
}

template <typename T1, typename T2>
void display(const map<T1, T2> &l)
{
    cout << "[ ";
    for (const auto &elem : l)
    {
        cout << elem.first << ":" << elem.second << " ";
    }
    cout << "]  " << endl;
}

void test1()
{
    // Maps
    cout << "\nTest1 =========================" << endl;
    map<string, int> m{
        {"Larry", 3},
        {"Moe", 1},
        {"Curly", 2}};
    display(m);

    m.insert(std::pair<string, int>("Anna", 10));
    display(m);

    m.insert(std::make_pair("Joe", 5)); //! Use this make_pair(x, y);
    display(m);

    m["Frank"] = 18;
    display(m);

    m["Frank"] += 10;
    display(m);

    m.erase("Frank");
    display(m);

    cout << "Count for Joe: " << m.count("Joe") << endl;
    cout << "Count for Frank: " << m.count("Frank") << endl;

    auto it = m.find("Larry");
    if (it != m.end()) //! it points to the pair, use -> first and second to access data of the pair
        cout << "Found: " << it->first << " : " << it->second << endl;

    m.clear();

    display(m);
}

void test2()
{
    cout << "\nTest2 =========================" << endl;

    map<string, std::set<int>> grades{
        {"Larry", {100, 90}},
        {"Moe", {94}},
        {"Curly", {80, 90, 100}}};

    display(grades);

    grades["Larry"].insert(95); //! insert 95 into the set of grades for "Larry"

    display(grades);

    auto it = grades.find("Moe");
    if (it != grades.end()) // found "Moe"
    {
        it->second.insert(1000); // insert 1000 into Moe's set of grades
    }                            // it->first is the key, it->second is the value (set)
    display(grades);
}

int main()
{
    test1();
    test2();
    return 0;
}