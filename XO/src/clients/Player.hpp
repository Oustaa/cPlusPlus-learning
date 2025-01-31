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

    Player(string name, char symbol)
    {
        this->name = name;
        this->symbol = symbol;
    }

    vector<int> get_played_spots()
    {
        return this->played_spots;
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

    virtual int play(Player *opponent) = 0;

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

class HumanPlayer : public Player
{
public:
    HumanPlayer(string player_name, char symbol) : Player(player_name, symbol) {}

    int play(Player *opponent) override
    {
        int spot = get_player_spot(played_spots);
        played_spots.push_back(spot);

        this->played_spots.push_back(spot);

        return spot;
    }
};

class Computer : public Player
{
    int played_count;

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
    int play(Player *opponent) override
    {

        vector<int> played_spots = merge_vector(this->played_spots, opponent->get_played_spots());

        int spot = 0;
        int wining_spot;

        vector<int> available_spots = get_available_spots(played_spots);

        // check if computer can win at a spot
        // if computer is can win, hw should play at his spot
        spot = this->winning_spot(played_spots);
        if (spot == 0)
        {
            // else check if the opponent is gonna win
            // if player can win, he should be blocked

            spot = opponent->winning_spot(played_spots);
            if (spot == 0)
            {
                // else just play at a rundom spot bellow
                random_device rd;
                mt19937 gen(rd());
                uniform_int_distribution<> dist(0, available_spots.size() - 1);
                spot = available_spots[dist(gen)];
            }
        }

        played_spots.push_back(spot);
        this->played_spots.push_back(spot);

        return spot;
    }
};
