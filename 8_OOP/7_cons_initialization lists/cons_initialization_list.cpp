/*
! TRUE INITIALIZATION


Before,  member value were set in the constructor body, order of initialization relies on the attributes declaration

* More efficient
* Initialization list follows the parameter list
* Ititializes the data members as the object is created!
* order of initialization is the order of declaration in the class

@brief adsadsad
@return asd

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

/*
#Before:

Player()

Player::Player(){
    name = "None";
    health = 0;
    xp = 0;
}

#!Best:

Player::Player()
    :name{"None"}, health{0}, xp{0}{

    }

*/

class Player
{
private:
    string name;
    int health;
    int xp;

public:
    Player();
    Player(string name);
    Player(string name, int health, int xp);
};

Player::Player()
    : name{"None"}, health{0}, xp{0}
{
}

Player::Player(string name_val)
    : name{name_val}, health{0}, xp{0}
{
}

Player::Player(string name_val, int health_val, int xp_val)
    : name{name_val}, health{health_val}, xp{health_val}
{
}

int main()
{
    Player empty;
    Player brayan{"Brayanobj"};
    Player villain{"Villain", 100, 50};

    return 0;
}