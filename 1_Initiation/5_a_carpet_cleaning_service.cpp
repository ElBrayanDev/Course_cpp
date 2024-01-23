/*
    Brayan Barrera Carpet Cleaning Service
    charges $30 per room
    Sales tax is 6%
    Estimates are valid for 30 days

    ask how many rooms he want to clean

    Estimate:
    Number or rooms: 2
    Price per room: $30
    Cost: $60
    Tax: $3.6
    =========================================
    Total estimate: $63.6
    This estimate is valid for 30 days
    */

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    cout << "\n\tHello, this is Brayan's Carpet Cleaning Service\n\n";

    cout << "Write the amount of rooms you want to get cleaned: ";
    int amount_rooms{0};
    cin >> amount_rooms;

    cout << "\n\nEstimate for carpet cleaning service\n";
    cout << "Number of rooms: " << amount_rooms << endl;
    cout << "Price per room is: $" << 30 << endl;
    cout << "Cost: $" << 30 * amount_rooms << endl;
    cout << "Tax: $" << 30 * amount_rooms * 0.06 << endl;
    cout << "===========================================" << endl;
    cout << "Total estimate: $" << (30 * amount_rooms)+(30 * amount_rooms * 0.06) << endl;
    cout<< "This estimate is valid for " << 30 << " days" << endl;

    //!WHAT IF PRICE IS CHANGED TO $35.2 
    //* if you find and replace, 30 days will also be replaced 
    // ? USE cons double price_per_rooom{35.2} this is unmodifiable
    // ? cons double sales_tax{0.006};
    // ? cons int estimate_expiry{30};
    return 0;
}