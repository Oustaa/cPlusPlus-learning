#include <iostream>

char WINNING_PATH[8][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {'1', '4', '7'},
    {'2', '5', '8'},
    {'3', '6', '9'},
    {'1', '5', '9'},
    {'3', '5', '7'},
};

class Player
{
public:
    std::string name;
    char tag;
    int played_count = 0;
    int wins = 0;

private:
    char playedAt[5] = {};

public:
    Player(std::string name, char tag, int wins = 0)
    {
        this->name = name;
        this->tag = tag;
        this->wins = wins;
    }

    void play(char spot)
    {
        this->playedAt[this->played_count] = spot;
        this->played_count++;
    }

    char *get_played_at()
    {
        return this->playedAt;
    }

    void reset_palyes()
    {
        this->played_count = 0;
        for (int i = 0; i < 5; i++)
        {
            this->playedAt[i] = '\n';
        }
    }

    int is_gonna_win(char opponent_played_spots[])
    {
        char spot;
        for (int i = 0; i < 8; i++)
        {
            int found = 0;
            for (int j = 0; j < 3; j++)
            {
                spot = WINNING_PATH[i][j];
                int arraySize = sizeof(WINNING_PATH[i]) / sizeof(WINNING_PATH[i][0]);
                if (std::find(WINNING_PATH[i], WINNING_PATH[i] + arraySize, this->playedAt[j]) != WINNING_PATH[i] + arraySize)
                {
                    ++found;
                }
            }
        }
    }
};