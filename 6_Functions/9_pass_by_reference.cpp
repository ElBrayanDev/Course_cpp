/*  PASS BY REFERENCE

! & - ampersand means the reference

# By using & 

- Sometimes we want to be able to change the actual parameter from within the function body

- In order to achieve this we need the location or address of the actual parameter

- We saw how this is the effect with array, but what about other variable types?

- We can use reference parameters to tell the compiler to pass in a reference to the actual parameter.

- The formal parameter will now be an alias for the actual parameter

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void pass_by_ref1(int &num);
void pass_by_ref2(string &s);
void pass_by_ref3(vector<string> &v);
void print_vector(const vector<string> &v); // const

void pass_by_ref1(int &num)
{
    num = 1000;
}

void pass_by_ref2(string &s)
{
    s = "Changed";
}

void pass_by_ref3(vector<string> &v)
{
    v.clear(); // delete all vector elements
}

void print_vector(const vector<string> &v)
{
    for (auto s : v)
        cout << s << " ";
    cout << endl;
}

int main()
{
    int num{10};
    int another_num{20};

    cout << "num before calling pass_by_ref1: " << num << endl;
    pass_by_ref1(num);
    cout << "num after calling pass_by_ref1: " << num << endl;

    cout << "\nanother_num before calling pass_by_ref1: " << another_num << endl;
    pass_by_ref1(another_num);
    cout << "another_num after calling pass_by_ref1: " << another_num << endl;

    string name{"Brayan"};
    cout << "\nname before calling pass_by_ref2: " << name << endl;
    pass_by_ref2(name);
    cout << "name after calling pass_by_ref2: " << name << endl;

    vector<string> stooges{"Larry", "Moe", "Curly"};
    cout << "\nstooges before calling pass_by_ref3: ";
    print_vector(stooges);
    pass_by_ref3(stooges);
    cout << "stooges after calling pass_by_ref3: ";
    print_vector(stooges);

    cout << endl;
    return 0;
}