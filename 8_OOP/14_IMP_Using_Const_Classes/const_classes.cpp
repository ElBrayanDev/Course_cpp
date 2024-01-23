/*
    USING CONST WITH CLASSES

! CONST - correctness
* Pass arguments to class member methods as const
* Can create const objects
! ALL YOUR GET METHODS SHOULD BE CONST

Having a const object, and calling a method,
the compiler thinks this method should change the object, so it gets an error
so we have to tell the compiler, some methods are const, and doesn't change object data
#CONST Function

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
    string get_name() const //# IMPORTANT the const, tells the compiler this method doesn't change data
    {
        // xp = 1000; //# I can't do this
        return name;
    }

    void set_name(string name)
    {
        this->name = name;
    }
    //#Overload const
    Player();
    Player(string name_val);
    Player(string name_val, int health_val, int xp_val);
};

Player::Player()
    : Player{"None", 0, 0} {}

Player::Player(string name_val)
    : Player{name_val, 0, 0} {}

Player::Player(string name_val, int health_val, int xp_val)
    : name{name_val}, health{health_val}, xp{xp_val} {}

void display_player_name(const Player &p)
{
    cout << p.get_name() << endl;
}

int main()
{
    const Player villain{"Villain", 999, 100};
    Player hero{"Hero", 500, 50};

    // villain.set_name("Villain Evolved"); //# This should never work, because villain is a const obj

    cout << villain.get_name() << endl; //# This could change the data, compiler error if method is not a const
    cout << hero.get_name() << endl;

    display_player_name(villain);
    display_player_name(hero);

    return 0;
}