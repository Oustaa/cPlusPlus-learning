#include <iostream>
#include <algorithm>

#include "./Player.h"

void drawMap(char spots[9], Player players[2]);
bool checkWining(Player *player);
void logArr(const int arr[], int arrLength);

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
    char playedSpot;
    int playedCount = 0, currentPlayerIndex = 0, draws;
    bool playerWins = false;
    std::string playerName;

    Player players[2] = {Player("X", 'X'), Player("O", 'O')};

    std::cout << "Enter first player name (X): ";
    std::getline(std::cin, playerName);
    players[0].name = playerName;

    std::cout << "Enter first player name (O): ";
    std::getline(std::cin, playerName);
    players[1].name = playerName;

    // the game main loop
    while (true)
    {
        // a single round loop
        while (playedCount <= 9)
        {
            playerWins = false;

            drawMap(spots, players);
            while (true)
            {
                std::cout << players[currentPlayerIndex].name << "(" << players[currentPlayerIndex].tag << ") Chose your spot: ";
                std::cin >> playedSpot;
                // add check for a not played spot
                // change this check
                //  playedSpot now is a char not an int
                if (playedSpot >= 1 && playedSpot <= 9)
                {
                    players[currentPlayerIndex].play(playedSpot);
                    break;
                }
                std::cout << "The Chosen spot is invalid\n";
            }

            spots[playedSpot - 1] = players[currentPlayerIndex].tag;

            if (playedCount > 4)
            {
                std::cout << "checking for winner";
                if (checkWining(&players[currentPlayerIndex]))
                {
                    std::cout << players[currentPlayerIndex].name << " wins;\n";
                    playedCount = true;

                    players[currentPlayerIndex].wins += 1;

                    // add file storage for players game history
                    return 0;
                }
            }

            currentPlayerIndex = currentPlayerIndex == 0 ? 1 : 0;
            playedCount++;
        }

        if (!playerWins)
        {
            draws += 1;
        }
    }

    return 0;
}

void drawMap(char spots[9], Player players[2])
{
    system("clear");

    std::cout << "---- XO -----\n";
    std::cout << "-------------\n";
    std::cout << "| X | 0 | O |\n";
    std::cout << "| " << players[0].wins << " | 0 | " << players[1].wins << " |\n";
    std::cout << "- GAME BOARD-\n";

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

bool checkWining(Player *player)
{
    int *spots = player->get_played_at();

    int existCount = 0;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int arraySize = sizeof(WINNING_PATH[i]) / sizeof(WINNING_PATH[i][0]);

            // check if spots[j] is in WINNING_PATH[i]
            if (std::find(WINNING_PATH[i], WINNING_PATH[i] + arraySize, spots[j]) != WINNING_PATH[i] + arraySize)
            {
                existCount++;
            }

            if (existCount == 3)
            {
                return true;
            }
        }
        existCount = 0;
    }

    return false;
}

void logArr(const int arr[], int arrLength)
{
    std::cout << "[";

    for (int i = 0; i < arrLength; i++)
    {
        std::cout << arr[i];

        if (i < arrLength - 1)
        {
            std::cout << ", ";
        }
    }

    std::cout << "]" << std::endl;
}

// ---- XO -----
// -------------
// | X | 0 | O |
// | 0 | 0 | 0 |
// - GAME BOARD-
// -------------
// | 1 | 2 | 3 |
// | 4 | 5 | 6 |
// | 7 | 8 | 9 |
// -------------