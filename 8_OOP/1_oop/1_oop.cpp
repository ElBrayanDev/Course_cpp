/* OOP

! Information hiding
? Inheritance
Pholimorphism

NOT a Panacea, bad code stills bad if made with OOP
NOT suitable for all problems

C++ OOP has a steeper leaning curve
! Up-front design

OOP programs are:
 * larger
 * slower
 * more complex

!CLASSES

Methods (functions), they can hide data and methods, provide a public interface

!OBJECTS

Created from a class
Has its ID
Can use the class methods

*/

#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using namespace std;

//! Creating Class

class Player
{
    //? attributes
    std::string name;
    int health{100};
    int xp{12};

    //* methods
    void talk(std::string);
    bool is_dead();
};

class Account
{
    // attributes
    std::string name{"Account"};
    double balance{0.0};

    // methods
    bool deposit(double);
    bool withdraw(double);
};

int main()
{
    Account brayan_account;
    Account pedro_account;

    Player brayan;
    Player hero;

    Player players[]{brayan, hero};

    std::vector<Player> player_vec{brayan};
    player_vec.push_back(hero);

    Player *enemy{nullptr};
    enemy = new Player;

    delete enemy;
}