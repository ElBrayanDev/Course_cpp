// Repeat Section 9 CHALLENGE BUT USE MODULARIZED PROGRAMMING
/*
    This challenge is about using a collection (list) of integers and allowing the user
    to select options from a menu to perform operations on the list.

    Your program should display a menu options to the user as follows:

    P - Print numbers
    A - Add a number
    M - Display mean of the numbers
    S - Display the smallest number
    L - Display the largest number
    Q - Quit

    Enter your choice:

The program should only accept valid choices from the user, both upper and lowercase selections should be allowed.
If an illegal choice is made, you should display, "Unknown selection, please try again" and the menu options should be
displayed again.


If the user enters 'P' or 'p', you should display all of the elements (ints) in the list.
If the list is empty you should display "[] - the list is empty"
If the list is not empty then all the list element should be displayed inside square brackets separated by a space.
For example, [ 1 2 3 4 5 ]

If the user enters 'A' or 'a' then you should prompt the user for an integer to add to the list
which you will add to the list and then display it was added. For example, if the user enters 5
You should display, "5 added".
Duplicate list entries are OK

If the user enters 'M' or 'm'  you should calculate the mean or average of the elements in the list and display it.
If the list is empty you should display, "Unable to calculate the mean - no data"

If the user enters 'S' or 's' you should display the smallest element in the list.
For example, if the list contains [2 4 5 1],  you should display, "The smallest number is 1"
If the list is empty you should display, "Unable to determine the smallest number - list is empty"

If the user enters 'L' or 'l' you should display the largest element in the list
For example, if the list contains [2 4 5 1], you should display, "The largest number is 5"
If the list is empty you should display, "Unable to determine the largest number - list is empty"

If the user enters 'Q' or 'q' then you should display 'Goodbye" and the program should terminate.

Before you begin. Write out the steps you need to take and decide in what order they should be done.
Think about what loops you should use as well as what you will use for your selection logic.

This exercise can be challenging! It may likely take a few attempts before you complete it -- that's OK!

Finally, be sure to test your program as you go and at the end.

Hint: Use a vector!

@author ElBrayan
@version 02/20/2023

*/

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int check_empty_list(const vector<int> &);
void print_menu(vector<int> &);
void action(char, vector<int> &);
void print_list(const vector<int> &);
void add_integer(vector<int> &);
void calc_mean(const vector<int> &);
void calc_smallest(const vector<int> &);
void calc_largest(const vector<int> &);
void calc_times_displayed(const vector<int> &);
void to_ascending(vector<int> &);
void to_descending(vector<int> &);
void clear_list(vector<int> &);

void clear_list(vector<int> &list)
{
    if (check_empty_list(list) == 1)
    {
        list.clear();
        cout << "Your list is clear now" << endl;
    }
    cout << endl;
}

void to_descending(vector<int> &list)
{
    int aux1{0};

    if (check_empty_list(list) == 1)
    {

        for (unsigned j = 0; j < list.size(); j++)
        {
            for (unsigned i = 0; i < list.size() - 1; i++)
            {
                if (list.at(i) < list.at(i + 1))
                {
                    aux1 = list.at(i);
                    list.at(i) = list.at(i + 1);
                    list.at(i + 1) = aux1;
                }
            }
        }
        cout << "Your list is now in descending order, print it to check" << endl;
    }
    cout << endl;
}

void to_ascending(vector<int> &list)
{
    int aux1{0};

    if (check_empty_list(list) == 1)
    {
        for (unsigned j = 0; j < list.size(); j++)
        {
            for (unsigned i = 0; i < list.size() - 1; i++)
            {
                if (list.at(i) > list.at(i + 1))
                {
                    aux1 = list.at(i);
                    list.at(i) = list.at(i + 1);
                    list.at(i + 1) = aux1;
                }
            }
        }
        cout << "Your list is now in ascending order, print it to check" << endl;
    }
    cout << endl;
}

void calc_times_displayed(const vector<int> &list)
{
    int times_displayed{0}, number{0};

    if (check_empty_list(list) == 1)
    {
        cout << "\nWrite the number you want to find: ";
        cin >> number;
        for (unsigned i{0}; i < list.size(); i++)
        {
            if (number == list.at(i))
            {
                times_displayed++;
            }
        }
        if (times_displayed == 0)
        {
            cout << number << " is not in the list" << endl;
            goto fin_f;
        }
        else
        {
            cout << "This number occurs " << times_displayed << " time(s) in the list" << endl;
        }
    fin_f:
        times_displayed = 0;
    }
    cout << endl;
}

void calc_largest(const vector<int> &temp)
{
    if (check_empty_list(temp) == 1)
    {
        int largest{0};
        largest = temp.at(0);
        for (unsigned i{0}; i < temp.size(); i++)
        {
            if (temp.at(i) > largest)
            {
                largest = temp.at(i);
            }
        }
        cout << "The largest number is: " << largest << endl;
    }
    cout << endl;
}

void calc_smallest(const vector<int> &temp)
{
    if (check_empty_list(temp) == 1)
    {
        int smallest{0};
        smallest = temp.at(0);

        for (unsigned i{0}; i < temp.size(); i++)
        {
            if (temp.at(i) < smallest)
            {
                smallest = temp.at(i);
            }
        }
        cout << "The smallest number is: " << smallest << endl;
    }
    cout << endl;
}

void calc_mean(const vector<int> &temp)
{
    int sum{0};

    if (check_empty_list(temp) == 1)
    {
        for (int c : temp)
        {
            sum += c;
        }

        cout << "The average of the list is: " << static_cast<double>(sum) / temp.size() << endl;
    }
    cout << endl;
}

void add_integer(vector<int> &list)
{
    int number{0};

    cout << "Add an integer to the list: ";
    cin >> number;
    list.push_back(number);
    cout << number << " added" << endl;
    cout << endl;
}

void print_list(const vector<int> &temp)
{
    if (check_empty_list(temp) == 1)
    {
        cout << "List: " << endl;
        for (unsigned i{0}; i < temp.size(); i++)
        {
            if (i == 0)
            {
                cout << "[";
            }
            cout << temp.at(i);

            if (i < temp.size() - 1)
            {
                cout << " ";
            }
        }
        cout << "]" << endl;
    }
    cout << endl;
}

void action(char s, vector<int> &list)
{
    switch (s)
    {
    case 'P':
        print_list(list);
        break;

    case 'A':
        add_integer(list);
        break;

    case 'M':
        calc_mean(list);
        break;

    case 'S':
        calc_smallest(list);
        break;

    case 'L':
        calc_largest(list);
        break;

    case 'F':
        calc_times_displayed(list);
        break;

    case '1':
        to_ascending(list);
        break;

    case '2':
        to_descending(list);
        break;

    case 'C':
        clear_list(list);
        break;

    case 'Q':
        break;

    default:
        cout << "\nUnknown selection, please try again." << endl;
        cout << endl;
        break;
    }
}

void print_menu(vector<int> &temp)
{
    char choice{};
    do
    {
        cout << "P - Print numbers" << endl;
        cout << "A - Add a number" << endl;
        cout << "M - Display mean of the numbers" << endl;
        cout << "S - Display the smallest number" << endl;
        cout << "L - Display the largest number" << endl;
        cout << "F - Search a number and get the number of times it occurs" << endl;
        cout << "1 - Order list upward" << endl;
        cout << "2 - Order list downward" << endl;
        cout << "C - Clear list" << endl;
        cout << "Q - Quit" << endl;

        cout << "\nEnter your choice: ";
        cin >> choice;
        choice = toupper(choice);
        cout << endl;

        action(choice, temp);

    } while (choice != 'Q');

    cout << "\tGoodbye !\n"
         << endl;
}

int check_empty_list(const vector<int> &list)
{
    if (list.size() == 0)
    {
        cout << "[] - the list is empty" << endl;
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
    vector<int> numbers{};

    print_menu(numbers);

    //! Check that you pass the vector by reference and through the program you modified it
    for (auto c : numbers)
    {
        cout << c << " | ";
    }

    return 0;
}