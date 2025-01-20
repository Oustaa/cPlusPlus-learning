#include <iostream>

#include "utils.h"

using namespace std;

class Player
{
    PlayersResult player_result{0, 0, 0};

public:
    string player_name;

    Player() {};

    Player(string name)
    {
        this->player_name = name;
    }
};
