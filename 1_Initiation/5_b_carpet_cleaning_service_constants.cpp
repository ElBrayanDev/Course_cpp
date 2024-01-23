#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    const double small_room_price{25}, large_room_price{35}, tax{0.06};
    const int time_valid{30};

    cout << "\nHow may small rooms do you want to get cleaned? " << endl;
    int amount_small_rooms;
    cin >> amount_small_rooms;

    cout << "How may large rooms do you want to get cleaned? " << endl;
    int amount_large_rooms;
    cin >> amount_large_rooms;

    cout << "Estimate for carpet cleaning service" << endl;
    cout << "Number of small rooms: " << amount_small_rooms << endl;
    cout << "Number of large rooms: " << amount_large_rooms << endl;
    cout << "Price per small room: $" << small_room_price << endl;
    cout << "Price per large room: $" << large_room_price << endl;
    cout << "Cost: $" << (amount_large_rooms * large_room_price) + (amount_small_rooms * small_room_price) << endl;
    cout << "Tax: $" << ((amount_large_rooms * large_room_price) + (amount_small_rooms * small_room_price)) * tax << endl;
    cout << "===============================================" << endl;
    cout << "Total estimate: $" << ((amount_large_rooms * large_room_price) + (amount_small_rooms * small_room_price)) + (((amount_large_rooms * large_room_price) + (amount_small_rooms * small_room_price)) * tax) << endl;
    cout << "This estimate is valid for " << time_valid << " days";

    return 0;
}