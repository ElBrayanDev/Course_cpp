#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void display(const vector<string> *const v)
{
    //(*v).at(0) = "Funny"; !const function
    for (auto str : *v)
        cout << str << " ";
    cout << endl;

    //   v = nullptr;
}

void display(int *array, int sentinel)
{
    while (*array != sentinel)
        cout << *array++ << " ";
    cout << endl;
}

int main()
{

    //    cout << "-----------------------------" << endl;
    //    vector<string> stooges {"Larry", "Moe", "Curly"};
    //    display(&stooges);

    cout << "\n-----------------------------" << endl;
    int scores[]{100, 98, 97, 79, 85, -1};
    display(scores, -1);

    cout << endl;
    return 0;
}