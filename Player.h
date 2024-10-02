#include <iostream>

int WINNING_PATH[8][3] = {
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
public:
    std::string name;
    char tag;
    int played_count = 0;
    int wins = 0, loses = 0, draws = 0;

private:
    int playedAt[5] = {};

public:
    Player(std::string name, char tag)
    {
        this->name = name;
        this->tag = tag;
    }

    void play(int spot)
    {
        this->playedAt[this->played_count] = spot;
        this->played_count++;
    }

    int *get_played_at()
    {
        return this->playedAt;
    }
};