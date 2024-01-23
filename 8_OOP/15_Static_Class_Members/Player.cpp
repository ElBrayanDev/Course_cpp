#include "Player.h"

int Player::num_active_players{0}; //! IMPORTANT, we can't initialize value on Player.h

Player::Player(string name_val, int health_val, int xp_val)
    : name{name_val}, health{health_val}, xp{xp_val}
{
    ++num_active_players; //# Increment active players
}
//#Copy Ctor
Player::Player(const Player &source)
    : Player{source.name, source.health, source.xp}
{
}

Player::~Player()
{
    --num_active_players; //# Decrement active players
}

int Player::get_num_active_players()
{
    return num_active_players;
}