/*
!Define behaviour (value) for atributes of an object created with no args

Ex:

class Account
{
private:
    string name;
    double balance;
public:
    Account ()
    {
        name = "None";
        balance = 0.0;
    }
    bool withdraw(double amount);
    bool deposit(double amount);
};

If you declare a constructor with args, you cannot expect an auto generated - default empty constructure,
! you must define it yourself.

Constructors must be unique, and a class can have as many as needed
Best is to initialize al parameters on all constructors, don't have garbage data
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
    string get_name()
    {
        return name;
    }
    Player() // default initializer
    {
        name = "non";
        health = 1;
        xp = 0;
    }
    Player(string name_val, int health_val, int xp_val)
    {
        name = name_val;
        health = health_val;
        xp = xp_val;
    }
};

int main()
{
    Player brayan; //! I can do this if: there are no cons (default empty), or if I manually create the no args constructor
    brayan.set_name("Brayan");
    cout << brayan.get_name() << endl;
    Player brayan_charged("Super Brayan Evolved", 100, 12);
    cout << "Name is: " << brayan_charged.get_name() << endl;

    return 0;
}