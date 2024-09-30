#include <iostream>
#include "./Player.h"

void drawMap(char spots[9]);
bool checkWining(int spots[5]);

int main()
{
    char spots[9] = {
        '1',
        '2',
        '3',
        '4',
        '5',
        '6',
        '7',
        '8',
        '9'};
    int playedCount = 0, playedSpot, currentPlayerIndex = 0;
    std::string playerName;

    Player players[2] = {Player("X", 'X'), Player("O", 'O')};

    std::cout << "Enter first player name (X): ";
    std::getline(std::cin, playerName);
    players[0].name = playerName;

    std::cout << "Enter first player name (O): ";
    std::getline(std::cin, playerName);
    players[1].name = playerName;

    while (true)
    {
        while (playedCount <= 9)
        {
            drawMap(spots);
            std::cout << players[currentPlayerIndex].name << " Turn (" << players[currentPlayerIndex].tag << "):\n";
            while (true)
            {
                std::cout << "Chose your spot: ";
                std::cin >> playedSpot;
                // add check for a not played spot
                if (playedSpot >= 1 && playedSpot <= 9)
                {
                    break;
                }
                std::cout << "The Chosen spot is invalid\n";
            }

            spots[playedSpot - 1] = players[currentPlayerIndex].tag;

            // checkWining(players[currentPlayerIndex].playedAt);

            currentPlayerIndex = currentPlayerIndex == 0 ? 1 : 0;
            playedCount++;
        }
    }

    return 0;
}

void drawMap(char spots[9])
{
    std::cout << "-------------\n";
    for (int i = 0; i < 9; i++)
    {

        std::cout << "| " << spots[i] << " ";

        if ((i + 1) % 3 == 0)
        {
            std::cout << "|\n";
        }
    }

    std::cout << "-------------\n";
}

bool checkWining(int spots[5])
{
    int existCount = 0;

    for (int i = 0; i < 8; i++)
    {
        for (int j; j < 5; j++)
        {
            // check if spots[j] is in WINNING_PATH[i]
            // if true existCount

            // if  existCount == 3 then return true
        }
        existCount = 0;
    }

    return false;
}
