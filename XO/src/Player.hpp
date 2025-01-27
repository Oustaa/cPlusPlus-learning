#include <iostream>
#include <vector>
#include <algorithm>

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

    int get_player_spot(vector<int> played_spots)
    {
        int played_spot;

        do
        {
            cout << name << " chose a spot (" << symbol << "): ";
            cin >> played_spot;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(1000, '\n');
            }

            if (played_spot < 1 || played_spot > 9 || find(played_spots.begin(), played_spots.end(), played_spot) != played_spots.end())
                cout << "invalid input!!!!!!" << endl;
            else
                break;

        } while (true);

        return played_spot;
    }

    virtual int play(vector<int> played_spots)
    {
        int spot = get_player_spot(played_spots);
        played_spots.push_back(spot);

        this->played_spots.push_back(spot);

        return spot;
    }

    PlayeScore get_score()
    {
        return playe_score;
    }

    void clear()
    {
        played_spots.clear();
    }

    bool check_wins()
    {

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
            {
                playe_score.wins++;
                return true;
            }
        }

        return false;
    }

    int will_player_win(vector<int> opponent_spots)
    {
        int checking_spot;
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
                checking_spot = spot;
            }

            if (match == 3)
            {
                playe_score.wins++;
                return true;
            }
        }

        return 0;
    }
};

class Computer : public Player
{
public:
    Computer(char symbol) : Player("computer", symbol) {}

    /**
     * @brief
     * computer play is defirent from player's play, instead of getting a spot he must figure it out. how to do it
     *
     * @param
     * Player opponent => for played spots,
     *
     * @return
     * int player_spot
     */
    int play(vector<int> played_spots) override
    {
        cout << "fuck this shit" << endl;
        return 1;
    }
};
