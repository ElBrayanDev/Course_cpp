/*
# Exception from functions

A fuction might throw an exception, that we have to handle in the block
where we called that function

*/

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <cmath>
#include <cctype>
#include <memory>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

double calculate_mpg(int miles, int gallons)
{
    if (gallons == 0)
        throw 0;
    return static_cast<double>(miles) / gallons;
}

int main()
{
    int miles{};
    int gallons{};
    double miles_per_gallon{};

    std::cout << "Enter the miles: ";
    std::cin >> miles;
    std::cout << "Enter the gallons: ";
    std::cin >> gallons;
    try
    {
        miles_per_gallon = calculate_mpg(miles, gallons);
        std::cout << "Result: " << miles_per_gallon << std::endl;
    }
    catch (int &ex)
    {
        std::cerr << "Tried to divide by zero" << std::endl;
    }
    std::cout << "Bye" << std::endl;

    return 0;
}
