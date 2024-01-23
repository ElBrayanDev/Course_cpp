/*  USING DEBUGGER
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

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{

    int i{5};
    while (i > 0)
    {
        cout << i << endl;
        i--;
    }

    int x{100}, y{200};
    cout << "\nx: " << x << endl;
    cout << "y: " << y << endl;

    swap(&x, &y);

    cout << "\nx: " << x << endl;
    cout << "y: " << y << endl;
    cout << endl;
    return 0;
}