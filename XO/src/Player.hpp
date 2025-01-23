#include <iostream>
#include <vector>
#include <algorithm>

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
        int winning_paths[8][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9},
            {1, 4, 7},
            {2, 5, 8},
            {3, 6, 9},
            {1, 5, 9},
            {3, 5, 7},
        };

        for (const auto &path : winning_paths)
        {
            int match = 0;
            for (auto spot : path)
            {
                auto it = find(played_spots.begin(), played_spots.end(), spot);

                if (it != played_spots.end())
                {
                    match++;
                }
            }

            if (match == 3)
                return true;
        }

        return false;
    }
};
