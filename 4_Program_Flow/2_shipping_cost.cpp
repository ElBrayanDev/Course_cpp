/*
    Shipping cost calculator

    Ask the user for package dimension in inches
    length, width, height - these should be integers

    All dimension must be 10 inches or less or we cannot ship it

    Base cost $2.50
    If package volume is greater than 100 cubic inches there is a 10% surcharge
    If package volume is greater than 500 cubic inches there is a 25% surcharge

*/

#include <iostream>
#include <vector>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;
using std::vector;

int main()
{
    int length{}, width{}, height{};
    const int max_measures{10};
    const double base_cost{2.50};
    const double surcharge_hundred{0.1};
    const double surcharge_5hundred{0.25};
    double final_cost;

    cout << "\n\tEnter the measures of the package in inches." << endl;

enter_length:
    cout << "\nLength: ";
    cin >> length;
    if (length > max_measures)
    {
        cout << "That length is not valid, it must be equal or less than " << max_measures << " inches.\n";
        goto enter_length;
    }
enter_width:
    cout << "\nWidth: ";
    cin >> width;
    if (width > max_measures)
    {
        cout << "That width is not valid, it must be equal or less than " << max_measures << " inches.\n";
        goto enter_width;
    }
enter_height:
    cout << "\nHeight: ";
    cin >> height;
    if (height > max_measures)
    {
        cout << "That height is not valid, it must be equal or less than " << max_measures << " inches\n";
        goto enter_height;
    }
    double package_volume;
    package_volume = length * width * height;
    final_cost = base_cost;

    if (package_volume >= 500)
    {
        final_cost += base_cost * surcharge_5hundred;
    }
    else if (package_volume >= 100)
    {
        final_cost += base_cost * surcharge_hundred;
    }

    cout << fixed << setprecision(2);
    cout << "\n\n\t The final cost of the package is $" << final_cost << endl;

    return 0;
}