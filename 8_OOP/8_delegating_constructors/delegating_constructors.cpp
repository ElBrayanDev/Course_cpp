/* Delegating Constructors

The code for constructors is very similar.

!Avoid duplicating code

#Calls a constructor

given the cons Player(String name, int health, int xp);

we can make the no args cons like:

Player::Player(string name)
{
    : Player{"None", 0, 0} //! This is the call for the full args constructor
}

Code for one constructor can call another in the initialization list

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
    // OVERLOADED CONSTRUCTORS
    Player();
    Player(string name);
    Player(string name, int health, int xp);
};

Player::Player()
    : Player{"None", 0, 0}
{
    cout << "No args constructor" << endl;
}

Player::Player(string name_val)
    : Player{name_val, 0, 0}
{
    cout << "Name arg cons" << endl;
}

Player::Player(string name_val, int health_val, int xp_val)
    : name{name_val}, health{health_val}, xp{health_val}
{
    cout << "Full constructor" << endl;
}

int main()
{
    Player empty;
    Player brayan{"Brayanobj"};
    Player villain{"Villain", 100, 50};

    return 0;
}