/* Section Challenge

  Write a C++ function named apply_all that expects two arrays of integers and their sizes and
  dynamically allocates a new array of integers whose size is the product of the 2 array sizes

  The function should loop through the second array and multiplies each element across each element of array 1 and store the
  product in the newly created array.

  The function should return a pointer to the newly allocated array.

  You can also write a print function that expects a pointer to an array of integers and its size and display the
  elements in the array.

  For example,

  Below is the output from the following code which would be in main:

    int array1[] {1,2,3,4,5};
    int array2[] {10,20,30};

    cout << "Array 1: " ;
    print(array1,5);

    cout << "Array 2: " ;
    print(array2,3);

    int *results = apply_all(array1, 5, array2, 3);
    cout << "Result: " ;
    print(results,15);

   Output
   ---------------------
   Array 1: [ 1 2 3 4 5 ]
   Array 2: [ 10 20 30 ]
   Result: [ 10 20 30 40 50 20 40 60 80 100 30 60 90 120 150 ]
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

int *apply_all(int *array1, const size_t size1, int *array2, const size_t size2)
{
    size_t size3 = (size1 * size2);
    int *array3 = new int[size3];

    size_t i{0}; //! position in array3

    for (size_t k{0}; k < size2; ++k)
    {
        for (size_t j{0}; j < size1; ++j)
        {
            *(array3 + i) = (*(array2 + k)) * (*(array1 + j));
            ++i;
        }
    }
    return array3;
}

const void print(int *arr_ptr, size_t size)
{
    cout << endl
         << "[ ";
    for (size_t i{0}; i < size; ++i)
    {
        cout << *(arr_ptr + i) << " ";
    }
    cout << "]";
    cout << endl
         << endl;
}

int main()
{
    const size_t array1_size{5};
    const size_t array2_size{3};

    int array1[]{1, 2, 3, 4, 5};
    int array2[]{10, 20, 30};

    cout << "Array 1: ";
    print(array1, array1_size);

    cout << "Array 2: ";
    print(array2, array2_size);

    int *results = apply_all(array1, array1_size, array2, array2_size);
    constexpr size_t results_size{array1_size * array2_size};

    cout << "Result: ";
    print(results, results_size);

    cout << endl;

    return 0;
}
