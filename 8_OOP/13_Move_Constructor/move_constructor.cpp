/*
    MOVE CONSTRUCTOR

* Sometimes copy constructors are called many times automatically due to the copy semantics of C++
* Copy constructors doing deep copying can have a significant performance bottleneck
* C++11 introduced move semantics and MOVE CONSTRUCTOR
@ Move constructor moves an object rather than copying
? Optional but recommended when you have a raw pointer
! Copy elision - C++ may optimize copying away completely (RVO - Return Value Optimization) - You may not see the move or copy constructor being called
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
    int *data;

public:
    void set_data_value(int d) { *data = d; }
    int get_data_value() { return *data; }
    //# Constructor
    Player(int d = 0);
    //# Copy constructor
    Player(const Player &source);
    //# Move
    Player(Player &&source) noexcept;
    //# Destructor
    ~Player();
};

Player::Player(int d)
{
    data = new int;
    *data = d;
    cout << "Constructor for: " << d << endl;
}

//# Copy Ctor
Player::Player(const Player &source)
    : Player{*source.data}
{
    cout << "Copy constructor - deep copy for: " << *data << endl;
}

//# Move Ctor
Player::Player(Player &&source) noexcept
    : data{source.data}
{
    source.data = nullptr; //#! SUPER IMPORTANT
    cout << "Move constructor - moving resource: " << *data << endl;
}

//# Destructor

Player::~Player()
{
    if (data != nullptr)
    {
        cout << "Destructor freeing data for: " << *data << endl;
    }
    else
    {
        cout << "Destructor freeing data for nullptr" << endl;
    }
    delete data; //! SUPER IMPORTANT
}

int main()
{
    vector<Player> vec;

    vec.push_back(Player{10});
    vec.push_back(Player{20});
    vec.push_back(Player{30});
    vec.push_back(Player{40});
    vec.push_back(Player{50});
    vec.push_back(Player{60});
    vec.push_back(Player{70});
    vec.push_back(Player{80});

    return 0;
}