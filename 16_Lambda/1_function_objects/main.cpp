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

#include <functional>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

struct Square_Functor
{
    void operator()(int x) //! ADD THIS operator()
    {
        cout << x * x << " ";
    }
};

template <typename T>
struct Displayer
{
    void operator()(const T &data)
    {
        cout << data << " ";
    }
};

class Multiplier
{
private:
    int num{};

public:
    Multiplier(int n) : num{n} {}
    int operator()(int n) const
    {
        return n * num;
    }
};

int main()
{
    cout << "\nTest1 =================" << endl;
    Square_Functor square;
    square(4); //! square.operator()(4)     displays 16

    Displayer<int> d1;
    Displayer<string> d2;
    d1(100);     // displays 100
    d2("Frank"); // displays Frank

    cout << "\nTest2 =================" << endl;
    vector<int> vec1{1, 2, 3, 4, 5};
    vector<string> vec2{"Larry", "Moe", "Curly"};

    std::for_each(vec1.begin(), vec1.end(), square); //! doesn't modify, only prints square.operator(x) 1 4 9 16 25
    cout << endl;

    std::for_each(vec1.begin(), vec1.end(), Displayer<int>()); // 1 2 3 4 5
    cout << endl;

    std::for_each(vec1.begin(), vec1.end(), d1); // 1 2 3 4 5
    cout << endl;

    std::for_each(vec2.begin(), vec2.end(), Displayer<string>()); // Larry Moe Curly
    cout << endl;

    std::for_each(vec2.begin(), vec2.end(), d2); // Larry Moe Curly
    cout << endl;

    cout << "\nTest3 (Lambda) =================" << endl;
    std::for_each(vec1.begin(), vec1.end(), [](int x)
                  { cout << x * x << " "; }); // 1 4 9 16 25
    cout << endl;

    std::for_each(vec1.begin(), vec1.end(), [](int x)
                  { cout << x * 10 << " "; }); // 10 20 30 40 50
    cout << endl;

    std::for_each(vec1.begin(), vec1.end(), [](int x)
                  { cout << x << " "; }); // 1 2 3 4 5
    cout << endl;

    std::for_each(vec2.begin(), vec2.end(), [](string s)
                  { cout << s << " "; }); // Larry Moe Curly
    cout << endl;

    cout << "\nTest4 =================" << endl;
    Multiplier mult(100); //! Multiplies by 100
    vec1 = {1, 2, 3, 4};

    // transform changes the vector!
    std::transform(vec1.begin(), vec1.end(), vec1.begin(), mult); //? mult.operator(x) - x from vec1
    std::for_each(vec1.begin(), vec1.end(), d1);                  // 100 200 300 400
    cout << endl;

    // # Lambda
    vec1 = {1, 2, 3, 4};
    std::transform(vec1.begin(), vec1.end(), vec1.begin(), [](int x)
                   { return x * 100; });
    std::for_each(vec1.begin(), vec1.end(), [](int x)
                  { cout << x << " "; }); // 100 200 300 400 500

    cout << endl;

    return 0;
}