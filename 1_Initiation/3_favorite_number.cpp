#include <iostream>

int main()
{
	int favorite_number;

	std::cout << "Hello World, testing debug." << std::endl;

	std::cout << "Write your favorite number between 1 and 100: ";
	std::cin >> favorite_number;

	std::cout << favorite_number << " is my favorite number too!!" << std::endl;

	std::cout << "No really!! " << favorite_number << " is my favorite number!" << std::endl;

	return 0;
}