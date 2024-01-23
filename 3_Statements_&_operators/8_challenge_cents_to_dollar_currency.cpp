// Section 8 Challenge
/*
	For this program I will be using US dollars and cents.

	Write a program that asks the user to enter the following:
	An integer representing the number of cents

	You may assume that the number of cents entered is greater than or equal to zero

	The program should then display how to provide that change to the user.

	In the US:
		1 dollar is 100 cents
		1 quarter is 25 cents
		1 dime is 10 cents
		1 nickel is 5 cents, and
		1 penny is 1 cent.

	Here is a sample run:

	Enter an amount in cents :  92

	You can provide this change as follows:
	quarters : 3
	dollars    : 0
	dimes     : 1
	nickels   : 1
	pennies  : 2
*/
#include <iostream>

using namespace std;

int main()
{
	int cents{}, dollar{}, quarter{}, dime{}, nickel{}, penny{};

	cout << "Enter the amount of cents you have: ";
	cin >> cents;

		dollar = cents / 100;
		cents -= dollar * 100;

		quarter = cents / 25;
		cents -= quarter * 25;

		dime = cents / 10;
		cents -= dime * 10;

		nickel = cents / 5;
		cents -= nickel * 5;

		penny = cents;
		cents -= penny;

	cout << "Dollars	   :  " << dollar << endl;
	cout << "Quarters   :  " << quarter << endl;
	cout << "Dimes	   :  " << dime << endl;
	cout << "Nickels	   :  " << nickel << endl;
	cout << "Pennies	   :  " << penny << endl;
	cout << "Final cents (should be 0): " << cents << endl;

	return 0;
}