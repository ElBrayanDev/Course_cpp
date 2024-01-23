/*
# Scoped Enumerations

! use ::
*/

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
// Scoped enumeration holding the items for a grocery list
// The value of the enumerator could be the item code
enum class Grocery_Item //! this is enum class (scoped)
{
    Milk = 350,
    Bread = 250,
    Apple = 132,
    Orange = 100
};

// Used for test1
// Overloaded stream insertion operator.
// Inserts the name grocery item paramter to the input stream
std::ostream &operator<<(std::ostream &os, Grocery_Item grocery_item)
{
    std::underlying_type_t<Grocery_Item> value = std::underlying_type_t<Grocery_Item>(grocery_item);
    switch (grocery_item)
    {
    case Grocery_Item::Milk:
        os << "Milk";
        break;
    case Grocery_Item::Bread:
        os << "Bread";
        break;
    case Grocery_Item::Apple:
        os << "Apple";
        break;
    case Grocery_Item::Orange:
        os << "Orange";
        break;
    default:
        os << "Invalid item";
    }
    os << " : " << value;
    return os;
}

// Used for test1
// Returns a boolean depending on whether the Grocery_Item
// paramter is a valid enumerator or not.
bool is_valid_grocery_item(Grocery_Item grocery_item)
{
    switch (grocery_item)
    {
    case Grocery_Item::Milk:
    case Grocery_Item::Bread:
    case Grocery_Item::Apple:
    case Grocery_Item::Orange:
        return true;
    default:
        return false;
    }
}

// Used for test1
// Displays the grocery items in the grocery list
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
        cout << grocery_item << endl; // User the overloaded operator<<

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

// Using a scoped enumeration to model grocery items
void test1()
{
    cout << "\n--- Test1 --------------------------\n"
         << endl;

    vector<Grocery_Item> shopping_list;

    shopping_list.push_back(Grocery_Item::Apple);
    shopping_list.push_back(Grocery_Item::Milk);
    shopping_list.push_back(Grocery_Item::Orange);

    int Helicopter{1000};
    // shopping_list.push_back(Helicopter);                // Compiler error
    shopping_list.push_back(Grocery_Item(Helicopter)); //! casts Grocery_Item() Invalid item
    shopping_list.push_back(Grocery_Item(350));        // Will add Milk again!

    display_grocery_list(shopping_list);
}

// Used for test2
// A simple class that might model a Player in a game application.
// The player has a name, a mode that they are currently in, and a
// direction which they are facing.
class Player
{
    friend std::ostream &operator<<(std::ostream &os, const Player &p);

public:
    enum class Mode
    {
        Attack,
        Defense,
        Idle
    };
    enum class Direction
    {
        North,
        South,
        East,
        West
    };

    Player(string name, Mode mode = Mode::Idle, Direction direction = Direction::North) : name{name}, mode{mode}, direction{direction} {}

    string get_name() const { return name; }
    void set_name(string name) { this->name = name; }

    Mode get_mode() const { return mode; }
    void set_mode(Mode mode) { this->mode = mode; }

    Direction get_direction() const { return direction; }
    void set_direction(Direction direction) { this->direction = direction; }

private:
    string name;
    Mode mode;
    Direction direction;
};

// Used for test2
// A simple function that returns the string representation
// of the Player::Mode paramter passed into it.
string get_player_mode(Player::Mode mode)
{
    string result;
    switch (mode)
    {
    case Player::Mode::Attack:
        result = "Attack";
        break;
    case Player::Mode::Defense:
        result = "Defense";
        break;
    case Player::Mode::Idle:
        result = "Idle";
        break;
    };
    return result;
}

// Used for test2
// A simple function that returns the string representation
// of the Player::Direction paramter passed into it.
string get_player_direction(Player::Direction direction)
{
    string result;
    switch (direction)
    {
    case Player::Direction::North:
        result = "North";
        break;
    case Player::Direction::South:
        result = "South";
        break;
    case Player::Direction::East:
        result = "East";
        break;
    case Player::Direction::West:
        result = "West";
        break;
    };
    return result;
}

// Used for test2
// Overloading the output stream insertion operator
// so we can easily put Player objects on the output stream.
std::ostream &operator<<(std::ostream &os, const Player &p)
{
    os << "Player name:      " << p.get_name() << "\n"
       << "Player mode:      " << get_player_mode(p.mode) << "\n"
       << "Player direction: " << get_player_direction(p.direction)
       << endl;
    return os;
}

void test2()
{
    cout << "\n--- Test2 --------------------------\n"
         << endl;

    Player p1{"Cloud Strife", Player::Mode::Attack, Player::Direction::North};
    Player p2{"Tifa Lockhart", Player::Mode::Defense, Player::Direction::West};
    Player p3{"Sephiroth", Player::Mode::Idle, Player::Direction::South};

    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;
}

int main()
{
    test1();
    test2();
    cout << "\n";
    return 0;
}
