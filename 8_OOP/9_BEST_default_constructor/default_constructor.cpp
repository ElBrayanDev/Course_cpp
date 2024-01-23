/*
    DEFAULT CONSTRUCTOR

As we have a full args constructor, and provide data for any object created
! every object will have the data needed for the full args constructor
@ depending on how we create the object, we will override some data, and others will keep default

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
    //# ONE CONSTRUCTOR
    Player(string name = "None", int health = 0, int xp = 0);
};

Player::Player(string name_val, int health_val, int xp_val)
    : name{name_val}, health{health_val}, xp{xp_val}
{
    cout << "Full constructor" << endl;
}

int main()
{
    Player empty;
    Player brayan{"Brayanobj"};
    Player hero{"Hero", 100};
    Player villain{"Villain", 0, 50};

    return 0;
}