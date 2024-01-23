/*
* name
    + the name of the function
    + same rules as for variables
    + should be meaningful
    + usually a verb or verb phrase

* parameter list
    + the variables passed into the function
    + their types must be specified

* return type
    + the type of the data that is returned from the function

* body
    + the statements that are executed when the function is called
    + in curly braces {}
*/

//  AREA OF CIRCLE AND VOLUME OF A CYLINDER

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

// # FUNCTION PROTOTYPES

double area_circle(double radius);
double volume_cylinder(double radius, double height);

double const PI{3.14159};

int main()
{
    cout << "Enter the radius of the circle: " << endl;
    double radius{};
    cin >> radius;
    cout << "The area of the circle is: " << area_circle(radius) << endl;
    cout << "Enter the radius and the height of the cylinder \n"
         << endl;
    double height{};
    cin >> radius >> height;
    cout << "The volume of the cylinder is: " << volume_cylinder(radius, height) << endl;

    return 0;
}

double area_circle(double radius)
{
    double area = PI * pow(radius, 2);
    return area;
}

double volume_cylinder(double radius, double height)
{
    double volume = area_circle(radius) * height;
    return volume;
}