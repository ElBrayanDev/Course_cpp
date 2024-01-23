/*  REFERENCES

• An alias for a variable
• Must be initialized to a variable when declared
• Cannot be null
• Once initialized cannot be made to refer to a different variable
• Very useful as function parameters
• Might be helpful to think of a reference as a constant pointer that
automatically dereferenced
*/

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main()
{

    int num{100};
    int &ref{num};

    cout << num << endl;
    cout << ref << endl;

    num = 200;
    cout << "\n---------------------------------" << endl;
    cout << num << endl;
    cout << ref << endl;

    ref = 300;
    cout << "\n---------------------------------" << endl;
    cout << num << endl;
    cout << ref << endl;

    cout << "\n---------------------------------" << endl;
    vector<string> stooges{"Larry", "Moe", "Curly"};

    for (auto str : stooges)
        str = "Funny"; //! str is a COPY of the each vector element

    for (auto str : stooges) // No change
        cout << str << endl;

    cout << "\n---------------------------------" << endl;
    for (auto &str : stooges) //* str is a reference to each vector element
        str = "Funny";

    for (auto const &str : stooges) // notice we are using const
        cout << str << endl;        // now the vector elements have changed

    cout << endl;
    return 0;
}