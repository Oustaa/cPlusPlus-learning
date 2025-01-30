#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <random>

#include "utils.hpp"

using namespace std;

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

class Player
{

    PlayeScore playe_score{0, 0, 0};

protected:
    vector<int> played_spots;

public:
    string name;
    char symbol;

    Player() {};

    Player(vector<int> played_spots)
    {
        this->played_spots = played_spots;
    }

    int winning_spot(vector<int> opponent_spots)
    {
        for (const auto &path : winning_paths)
        {
            std::vector<int> path_copy(std::begin(path), std::end(path));

            for (int i = 0; i < 3; i++)
            {
                int spot = path[i];

                if (find(played_spots.begin(), played_spots.end(), spot) != played_spots.end())
                {
                    //   remove the spot from the copy int[]
                    path_copy.erase(std::remove(path_copy.begin(), path_copy.end(), spot), path_copy.end());
                }
                else if (find(opponent_spots.begin(), opponent_spots.end(), spot) != opponent_spots.end())
                {
                    path_copy.clear();
                    break;
                }
            }

            //  the copy int[] has an element return it
            if (path_copy.size() == 1)
            {
                return path_copy[0];
            }
        }

        return 0;
    }
};

int main()
{
    // case 1 => p1 {1, 2, 5}; p2{8, 6, 4}
    // case 1 => p1 {1, 2, 5}; p2{8, 6, 4}
    // case 2 => p1 {3, 2, 5}; p2{8, 6, 4}

    Player player_test(vector<int>{3, 2, 5});

    int winning_spot = player_test.winning_spot(vector<int>{1, 8, 7});

    if (winning_spot != 0)
        cout << "winign spot is " << winning_spot << endl;
    else
        cout << "the player will not win" << endl;

    return 0;
}