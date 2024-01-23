#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    double room_width{0}, room_length{0};

    cout << "Type the room width: ";
    cin >> room_width;
    cout << "Type the room length: ";
    cin >> room_length;

    cout << "The area of the room is: " << room_length * room_width << " square meters" << endl;
    return 0;
}