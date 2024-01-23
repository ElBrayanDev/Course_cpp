/* REFERENCE OF THE ARRAY IS PASSED TO THE FUNCTION

* Since we are passing the location of the array
* The function can modify the actual array!

void zero_array(int numbers [], size_t size) {
    for (size_t i{0}; i < size; ++i )
        numbers[i] = 0; // zero out array element
}

int main() {
    int my_numbers[] {1,2,3,4,5}7
    zero_array(my_numbers, 5) ; // my numbers is now zeroes!
    print_array(my_numbers, 5); 0 0 0 0 0
    return 0;
}

# const will avoid that you can modify the data of the array


? void zero_array(const int numbers [], size_t size) {
    for (size_t i{0}; i < size; ++i )
        numbers[i] = 0; //! Error
}
*/

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void print_array(const double array[], size_t size); //! CONST

void set_array(double array[], size_t size, double score);

int main()
{
    double scores[]{5, 4.3, 3.6, 2.2, 3.4};
    print_array(scores, 5);
    set_array(scores, 5, 5);
    print_array(scores, 5);

    return 0;
}

void print_array(const double array[], size_t size) //! CONST
{
    for (size_t i{0}; i < size; ++i)
    {
        cout << array[i] << " \t";
    }
    cout << endl;
}

void set_array(double array[], size_t size, double score)
{
    for (size_t i{0}; i < size; ++i)
    {
        array[i] = score;
    }
}