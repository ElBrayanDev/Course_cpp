/*
# What is an enumeration?

- A user-defined type that models a set of constant integral values

    • The days of the week (Mon,Tue, Wed, .)
    • The months of the year (Jan, Feb, Mar, ...)
    • The suits in a deck of cards (Clubs, Hearts, Spades, Diamonds)
    • The values in a deck of cards (Ace, Two, Three, ...)
    • States of a system (Idle, Defense_Mode, Attack_Mode, ...)
    • The directions on a compass (North, South, East, West)

Motivation
  Prior to enumerated types
   • Unnamed numerical constants
   • "Magic numbers"

    • These constants would be used as conditionals in control statements
    • Often, one would have no idea what an algorithm was doing

    •As a result, many algorithms suffered from low readability and high numbers of logic errors

# Syntax

! enum {Red, Green, Blue };   // Implicit initialization
enum {Red = 1, Green = 2, Blue = 3 };
enum {Red = 1, Green, Blue}; //? Explicit and implicit initialization
                2       3

*/

// # UNSCOPED ENUMERATORS

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <cctype>
#include <string>
#include <vector>
#include <cmath>
#include <memory>
#include <fstream>
#include <algorithm>
#include <numeric>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// Used for test1
enum Direction
{
    North = 1,
    South = 10,
    East, // 11
    West  // 12
};

// enum Street {Main, North, Elm};   // Error, can't use North again

// Used for test1
// This function expects a Direction paramater
// and returns its string representation
string direction_to_string(Direction direction)
{
    string result;
    switch (direction)
    {
    case North:
        result = "North";
        break;
    case South:
        result = "South";
        break;
    case East:
        result = "East";
        break;
    case West:
        result = "West";
        break;
    default:
        result = "Unknown direction";
    }
    return result;
}

// Simple example that shows the use of an unscoped enumeration
void test1()
{
    cout << "\n--- Test1 --------------------------\n"
         << endl;

    Direction direction{North};
    cout << "\nDirection " << direction << endl;
    cout << direction_to_string(direction) << endl;

    direction = West;
    cout << "\nDirection " << direction << endl;
    cout << direction_to_string(direction) << endl;

    // direction = 5;  // Compiler Error

    // Be careful casting since the compiler will assume
    // you know what you are doing!
    direction = Direction(100);
    cout << "\nDirection " << direction << endl; // Displays 100!
    cout << direction_to_string(direction) << endl;

    direction = static_cast<Direction>(100);
    cout << "\nDirection " << direction << endl; // Displays 100!
    cout << direction_to_string(direction) << endl;
}

// Used for test2
// Unscoped enumeration representing items for a grocery shopping list
enum Grocery_Item
{
    Milk,
    Bread,
    Apple,
    Orange
};

// Overloading the stream insertion operator to insert
// the string representation of the provided Grovery_Item
// parameter into the output stream
std::ostream &operator<<(std::ostream &os, const Grocery_Item grocery_item)
{
    switch (grocery_item)
    {
    case Milk:
        os << "Milk";
        break;
    case Bread:
        os << "Bread";
        break;
    case Apple:
        os << "Apple";
        break;
    case Orange:
        os << "Orange";
        break;
    default:
        os << "Invalid item";
    }
    return os;
}

// Used for test2
// Returns a boolean depending on whether the Grocery_Item
// paramter is a valid enumerator or not.

bool is_valid_grocery_item(Grocery_Item grocery_item)
{
    switch (grocery_item)
    {
    case Milk:
    case Bread:
    case Apple:
    case Orange:
        return true;
    default:
        return false;
    }
}

// Used for test2
// Given a vector of Grocery_Items, this function displays
// the string representation of each item using the overloaded
// operator<< function.
// This function also keeps track of how many valid and invalid items
// are in the provided vector by using the is_valid_grocery_item function
// written above.
void display_grocery_list(const vector<Grocery_Item> &grocery_list)
{
    cout << "Grocery List"
         << "\n==============================" << endl;
    int invalid_item_count{0};
    int valid_item_count{0};
    for (Grocery_Item grocery_item : grocery_list)
    {
        cout << grocery_item << endl; //! User the overloaded operator<<

        // Check that grocery is valid grocery item
        if (is_valid_grocery_item(grocery_item))
            valid_item_count++;
        else
            invalid_item_count++;
    }

    cout << "==============================" << endl;
    cout << "Valid items: " << valid_item_count << endl;
    cout << "Invalid items: " << invalid_item_count << endl;
    cout << "Total items: " << valid_item_count + invalid_item_count << endl;
}

// Using an unscoped enumeration to model grocery items
void test2()
{
    cout << "\n--- Test2 --------------------------\n"
         << endl;

    vector<Grocery_Item> shopping_list;

    shopping_list.push_back(Apple);
    shopping_list.push_back(Apple);
    shopping_list.push_back(Milk);
    shopping_list.push_back(Orange);

    //! Grocery_Item item = 100;                         // Compiler error

    // Be careful when casting
    int Helicopter{1000};

    shopping_list.push_back(Grocery_Item(Helicopter)); //! Invalid item
    shopping_list.push_back(Grocery_Item(0));          // Will add Milk again!

    display_grocery_list(shopping_list);
}

// Used for test3
// Unscoped enumerations holding the possible states
// and sequences of a rocket launch.
// Note the addition of the Unknown enumerator for the State enumeration.
enum State
{
    Engine_Failure,
    Inclement_Weather,
    Nominal,
    Unknown
};
enum Sequence
{
    Abort,
    Hold,
    Launch
};

// Used for test3
// # Overloading the stream extraction operator to allow a user
// # to enter the state of State enumeration.
// ! Note the use of underlying_type_t.

std::istream &operator>>(std::istream &is, State &state)
{
    // int user_input;   // Will also work
    std::underlying_type_t<State> user_input;
    is >> user_input;

    switch (user_input)
    {
    case Engine_Failure:
    case Inclement_Weather:
    case Nominal:
    case Unknown:
        state = State(user_input);
        break;
    default:
        cout << "User input is not a valid launch state." << endl;
        state = Unknown;
    }

    return is;
}

// Used for test3
// Overloading the stream insertion operator to insert
// the string representation of the provided Sequence
// parameter into the output stream
std::ostream &operator<<(std::ostream &os, const Sequence &sequence)
{
    switch (sequence)
    {
    case Abort:
        os << "Abort";
        break;
    case Hold:
        os << "Hold";
        break;
    case Launch:
        os << "Launch";
        break;
    }

    return os;
}

// Used for test3
// Displays an information message given the sequence parameter.
void initiate(Sequence sequence)
{
    cout << "Initiate " << sequence << " sequence!" << endl; // Uses overloaded operator<<
}

// Using unscoped enums to control a rocket launch
// Reads input from the user for the State of the rocket launch,
// and then determines wich Sequence to execute.
void test3()
{
    cout << "\n--- Test3 --------------------------\n"
         << endl;

    State state;
    cout << "Launch state: ";
    cin >> state; //! users the overloaded operator>>

    switch (state)
    {
    case Engine_Failure: // Abort if Engine Failure
    case Unknown:        // or Unknown!
        initiate(Abort);
        break;
    case Inclement_Weather:
        initiate(Hold);
        break;
    case Nominal:
        initiate(Launch);
        break;
    }
}

int main()
{
    test1();
    test2();
    test3();

    cout << "\n";
    return 0;
}