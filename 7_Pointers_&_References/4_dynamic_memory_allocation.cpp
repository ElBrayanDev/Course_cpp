/*//#  DYNAMIC MEMORY ALLOCATION

- We often don't know how much storage we need until we need it
- We can allocate storage for a variable at run time

- Recall C++ arrays
    + We had to explicitly provide the size and it was fixed
    + But vectors grow and shrink dynamically

- We can use pointers to access newly allocated heap storage

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
using std::string;
using std::vector;

int main()
{

    int *int_ptr{nullptr};
    int_ptr = new int;       // allocate the int on the heap
    cout << int_ptr << endl; // use it
    delete int_ptr;          // release it

    size_t size{0};
    double *temp_ptr{nullptr};

    cout << "How many temps? ";
    cin >> size;

    temp_ptr = new double[size]; // allocate the storage on the heap
    cout << temp_ptr << endl;    // use it
    delete[] temp_ptr;           // release it

    cout << endl;
    return 0;
}