#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    const double usd_per_eur{ 0.98 };

    cout << "\n\tWelcome to EUR to USD converter" << endl;
    cout << "\nEnter the value in euros: ";
    double euros;
    cin >> euros;

    int dollars = euros * usd_per_eur;

    cout << "\n\t€" << euros << " equasls " << "$" << dollars;
    cout << endl;
    return 0;
}