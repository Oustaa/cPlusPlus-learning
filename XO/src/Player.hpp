#include <iostream>
#include <vector>

#include "utils.hpp"

using namespace std;

class Player
{
    vector<int> played_spots;

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
        played_spots.push_back(spot);
    }

    bool check_wins()
    {

        system("clear");
        vector<int>::iterator itr = played_spots.begin();

        while (itr != played_spots.end())
        {
            cout << *itr << endl;

            itr++;
        }

        return false;
    }
};
