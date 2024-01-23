/*
    COPY CONSTRUCTOR

Copying an object

#USES:

* Passing object by value as a parameter
* Returning an object from a function by value
* Constructing one object based on another of the same class

? C++ will provide a compiler-defined copy constructor if you don't define one

!BEWARE, if you have a pointer, only the pointer will be copied, no the data

#BEST PRACTICES:

* Provide a copy constructor when your class has raw pointer members
* Provide the copy constructor with a //!const reference parameter
* Use STL classes as they already provide copy constructors
* Avoid using raw pointer data members if possible (smart pointers)

*/

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Player
{
private:
    string name;
    int health;
    int xp;

public:
    string get_name() { return name; }
    int get_health() { return health; }
    int get_xp() { return xp; }
    Player(string name = "None", int health = 0, int xp = 0);

    //#COPY CONSTRUCTOR

    Player(const Player &source);

    //#Destructor
    ~Player()
    {
        cout << "Destructor called for: " << name << endl;
    }
};

Player::Player(string name_val, int health_val, int xp_val)
    : name{name_val}, health{health_val}, xp{xp_val}
{
    cout << "Full constructor called for: " << name << endl;
}

//#COPY CONSTRUCTOR

Player::Player(const Player &source)
    // : name(source.name), health(source.health), xp(source.xp) // Initializing
    : Player{source.name, source.health, source.xp} //! DELEGATING CONSTRUCTOR
{
    cout << "Copy made from: " << source.name << endl;
}
//#

void display_player(Player p)
{
    cout << "Name: " << p.get_name() << endl;
    cout << "Health: " << p.get_health() << endl;
    cout << "XP: " << p.get_xp() << endl;
}

int main()
{
    Player empty{"ZZZZZZZ", 999, 12};

    Player empty_object_copy {empty};

    cout << "Empty display: " << endl;
    display_player(empty);

    Player brayan{"Brayanobj"};
    Player hero{"Hero", 100};
    Player villain{"Villain", 0, 50};

    return 0;
}