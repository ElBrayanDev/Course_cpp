// Section 9

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

! Additional functionality if you wish to extend this program.

* search for a number in the list and if found display the number of times it occurs in the list
? clearing out the list (make it empty again) (Hint: the vector class has a .clear() method)
 don't allow duplicate entries
 come up with your own ideas!
! upward and downward ordering 10/15/2022
Good luck!

@author ElBrayan
@version 10/15/2022
*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> list{};

    char choice;
    int number{0};
    int sum{0};
    int smallest{0};
    int largest{0};
    int times_displayed{0};

    int aux1{0};

    cout << endl;
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
        cout << endl;

        switch (choice)
        {
        case 'P':
        case 'p':
            if (list.size() == 0)
            {
                cout << "[] - the list is empty" << endl;
            }
            else
            {
                cout << "\nList: " << endl;
                for (unsigned i{0}; i < list.size(); i++)
                {
                    if (i == 0)
                    {
                        cout << "[";
                    }
                    cout << list.at(i);

                    if (i < list.size() - 1)
                    {
                        cout << " ";
                    }
                }
                cout << "]" << endl;
            }
            cout << endl;
            break;

        case 'A':
        case 'a':
            cout << "Add an integer to the list: ";
            cin >> number;
            list.push_back(number);
            sum += number;
            cout << number << " added" << endl;
            cout << endl;
            break;

        case 'M':
        case 'm':
            if (list.size() == 0)
            {
                cout << "Unable to calculate the mean - no data" << endl;
            }
            else
            {
                cout << "The average of the list is: " << static_cast<double>(sum) / list.size() << endl;
            }
            cout << endl;
            break;

        case 'S':
        case 's':
            if (list.size() == 0)
            {
                cout << "Unable to determine the smallest number - list is empty" << endl;
            }
            else
            {
                smallest = list.at(0);

                for (unsigned i{0}; i < list.size(); i++)
                {
                    if (list.at(i) < smallest)
                    {
                        smallest = list.at(i);
                    }
                }
                cout << "The smallest number is: " << smallest << endl;
            }
            cout << endl;
            break;

        case 'L':
        case 'l':
            if (list.size() == 0)
            {
                cout << "Unable to determine the largest number - list is empty" << endl;
            }
            else
            {
                largest = list.at(0);

                for (unsigned i{0}; i < list.size(); i++)
                {
                    if (list.at(i) > largest)
                    {
                        largest = list.at(i);
                    }
                }
                cout << "The largest number is: " << largest << endl;
            }
            cout << endl;
            break;

        case 'f':
        case 'F':
            if (list.size() == 0)
            {
                cout << "[] - the list is empty" << endl;
                cout << endl;
            }
            else
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
                cout << endl;
            }
            break;

            //! 10/15/2022 added function for upward and downward list ordering

        case '1':
            if (list.size() == 0)
            {
                cout << "[] - the list is empty" << endl;
                cout << endl;
            }
            else
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
            break;

        case '2':
            if (list.size() == 0)
            {
                cout << "[] - the list is empty" << endl;
                cout << endl;
            }
            else
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
            break;

        case 'c':
        case 'C':
            if (list.size() == 0)
            {
                cout << "No need of that, list is already empty" << endl;
            }
            else
            {
                list.clear();
                cout << "Your list is clear now" << endl;
                sum = 0;
            }
            cout << endl;
            break;

        case 'q':
        case 'Q':
            break;

        default:
            cout << "\nUnknown selection, please try again." << endl;
            cout << endl;
            break;
        }
    } while (choice != 'q' && choice != 'Q');

    cout << "\tGoodbye" << endl;

    return 0;
}