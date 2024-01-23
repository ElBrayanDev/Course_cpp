/*
    STATIC CLASS MEMBERS

* CLass data members can be declared as static
    * single data member that belongs to the class,//! not the objects
    ? useful to store class-wide information

* Class functions can be declared as static
    * Independent of any objects
    * Can be called using the class name
*/

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include "Player.h" //# IMPORTANT

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void display_active_players()
{
    cout << "Active players: " << Player::get_num_active_players() << endl;
}

int main()
{
    display_active_players();
    Player hero{"Hero"};
    display_active_players();

    {
        Player brayan{"Brayan"};
        display_active_players(); // Should display 2
    }                             // Brayan gets killed

    display_active_players(); // should get back to 1

    Player *enemy = new Player("Enemy", 999, 100);
    display_active_players();
    delete enemy;
    display_active_players();

    return 0;
}