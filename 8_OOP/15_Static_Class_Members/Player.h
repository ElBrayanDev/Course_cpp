#ifndef PLAYER_H
#define PLAYER_H

#pragma once
#include <string>

using std::string;

class Player
{
private:
    static int num_active_players; //! NEW
    string name;
    int health;
    int xp;

public:
    string get_name() const { return name; }
    int get_health() const { return health; }
    int get_xp() const { return xp; }

    //# Ctor
    Player(string name_val = "None", int health_val = 0, int xp_val = 0);
    //# Copy Ctor
    Player(const Player &source);
    //# Destructor
    ~Player();

    static int get_num_active_players(); //! CLASS FUNCTION
};

#endif