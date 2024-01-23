/* CONSTRUCTORS

Special member method,evoke during object creation.

! Useful for initialization
Same name as the class

No return type specified

! Can be OVERLOADED, very used in C++

*/

/* DESTRUCTORS

Special member method, invoked automatically when object is destroyed

Same name as class, procedeed with a (~) tilde

No return type, or parameters

1 Destructor per class, no overload

Useful for memory and resources releasing

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
    void set_name(string name_val)
    {
        name = name_val;
    }
    // Overloaded Constructors
    Player()
    {
        cout << "No args constructor called" << endl;
    }
    Player(string name)
    {
        cout << "String arg constructor called" << endl;
    }
    Player(string name, int health, int xp)
    {
        cout << "Three args constructors called" << endl;
    }
    ~Player()
    {
        cout << "Destructor called for " << name << endl;
    }
};

int main()
{
    {
        Player slayer;
        slayer.set_name("Slayer");
    }

    {
        Player brayan;
        brayan.set_name("Brayan");
        Player hero("Hero");
        hero.set_name("Hero2");
        Player villain("Villain", 100, 15);
        villain.set_name("Villain");
    }

    Player *enemy = new Player;
    enemy->set_name("Enemy");

    Player *level_boss = new Player("Level Boss", 1000, 300);
    level_boss->set_name("Level Boss");

    delete enemy;
    delete level_boss;

    return 0;
}