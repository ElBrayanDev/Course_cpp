#include <iostream>
#include <vector>

using namespace std;

int main()
{
    for (int i{0}; i <= 12; i++)
    {
        for (int j{0}; j <= 12; j++)
        {
            cout << i << " * " << j << " = " << i * j << endl;
        }
        cout << endl;
    }
    return 0;
}