/*
Arrow operator
 */
#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
// using namespace std;

//! Creating Class

class Player
{
public: //! for now
    //? attributes
    std::string name;
    int health{100};
    int xp{12};

    //* methods
    void talk(std::string text_to_say)
    {
        cout << name << " says " << text_to_say << endl;
    }
    bool is_dead();
};

class Account
{
public: //! for now
    // attributes
    std::string name{"Account"};
    double balance{0.0};

    // methods
    bool deposit(double bal)
    {
        balance += bal;
        cout << "In deposit" << endl;
    }
    bool withdraw(double bal)
    {
        balance -= bal;
        cout << "In withdraw" << endl;
    }
};

int main()
{
    Account brayan_account;
    brayan_account.name = "Brayan's Account";
    brayan_account.balance = 5000.00;

    brayan_account.deposit(1000.00);
    brayan_account.withdraw(500.00);

    Account *pointer_account = new Account;
    pointer_account->name = "Pointer Method Account";
    pointer_account->balance = .99;
    pointer_account->deposit(999.01);
    pointer_account->withdraw(499.99);

    Player brayan;
    brayan.name = {"Brayan"};
    brayan.health = 250;
    brayan.xp = 24;
    brayan.talk("Hello budds");

    Player *enemy = new Player;
    (*enemy).name = "Enemy"; // dereference the pointer, to get a enemy object
    (*enemy).health = 100;
    enemy->xp = 15; // arrow operator

    enemy->talk("I will destroy you");
}