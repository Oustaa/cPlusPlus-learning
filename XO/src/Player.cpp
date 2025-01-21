#include <iostream>
#include <vector>

#include "utils.h"

using namespace std;

class Player
{

    vector<int> played_spot;

    // rename this var it's not ideal
    PlayeScore playe_score{0, 0, 0};

public:
    string name;
    char symbol;

    Player() {};

    Player(string name, char symbol)
    {
        this->name = name;
        this->symbol = symbol;
    }

    void play(int spot)
    {
        played_spot.push_back(spot);
    }

    bool check_wins()
    {
        return false;
    }
};
