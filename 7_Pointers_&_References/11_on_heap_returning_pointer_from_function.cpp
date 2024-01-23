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

int *create_array(size_t size, int init_value = 0)
{
    int *new_storage{nullptr};
    new_storage = new int[size]; //! ON HEAP int[]
    for (size_t i{0}; i < size; ++i)
        *(new_storage + i) = init_value;
    return new_storage;
}

void display(const int *const array, size_t size)
{
    for (size_t i{0}; i < size; ++i)
        cout << array[i] << " ";
    cout << endl;
}
int main()
{
    int *my_array{nullptr};
    size_t size;
    int init_value{};

    cout << "\nHow many integers would you like to allocate? ";
    cin >> size;
    cout << "What value would you like them initialized to? ";
    cin >> init_value;

    my_array = create_array(size, init_value);
    cout << "\n--------------------------------------" << endl;

    display(my_array, size);
    delete[] my_array;
    return 0;
}