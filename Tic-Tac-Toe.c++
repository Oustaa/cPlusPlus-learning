#include <iostream>
#include <algorithm>
#include <string>

#include "./Player.h"

void drawMap(char spots[9], Player players[2]);
bool checkWining(Player *player);
void logArr(const int arr[], int arrLength);
int after_game_menu();
int string_to_int(const std::string &str);

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
    int playedCount = 0, currentPlayerIndex = 0, draws, after_game_command;
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
            playedCount++;
            playerWins = false;

            drawMap(spots, players);

            while (true)
            {
                std::cout << players[currentPlayerIndex].name << "(" << players[currentPlayerIndex].tag << ") Chose your spot: ";
                std::cin >> playedSpot;
                // add check for a not played spot
                // change this check
                //  playedSpot now is a char not an int
                if (std::find(spots, spots + 9, playedSpot) != spots + 9)
                {
                    players[currentPlayerIndex].play(playedSpot);
                    break;
                }
                std::cout << "The Chosen spot is invalid\n";
            }

            if (playedCount >= 5)
            {
                if (checkWining(&players[currentPlayerIndex]))
                {
                    std::cout << players[currentPlayerIndex].name << " wins;\n";
                    playedCount = true;

                    players[currentPlayerIndex].wins += 1;

                    // add file storage for players game history
                    break;
                }
            }

            spots[string_to_int(&playedSpot) - 1] = players[currentPlayerIndex].tag;

            currentPlayerIndex = currentPlayerIndex == 0 ? 1 : 0;
        }

        if (!playerWins)
        {
            draws += 1;
        }

        // Print the after game menu
        after_game_command = after_game_menu();

        switch (after_game_command)
        {
        case 1:
            players[0].reset_palyes();
            players[1].reset_palyes();
            for (int i = 1; i < 10; i++)
            {
                spots[i] = i;
            }

            break;
        case 2:
            break;
        case 0:
            return 0;
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
    char *spots = player->get_played_at();

    int existCount = 0;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int arraySize = sizeof(WINNING_PATH[i]) / sizeof(WINNING_PATH[i][0]);
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

int after_game_menu()
{
    int answerInt;
    char answer;

    std::cout << "0 >> for exiting the game\n";
    std::cout << "1 >> for replaying\n";
    std::cout << "2 >> for change opponent\n";

    do
    {
        std::cout << ">> ";
        std::cin >> answer;
        answerInt = string_to_int(&answer);

        std::cout << "your answer as number is " << answerInt;

        if (answerInt == 0 || answerInt == 1 || answerInt == 2)
        {
            return answerInt;
        }

        std::cout << "The answer you entred is invalid";

    } while (true);
}

int string_to_int(const std::string &str)
{
    try
    {
        // std::stoi converts the string to an integer
        int num = std::stoi(str);
        return num;
    }
    catch (const std::invalid_argument &e)
    {
        // This exception is thrown if the input cannot be converted to an integer
        std::cerr << "Invalid input: '" << str << "' cannot be converted to an integer.\n";
    }
    catch (const std::out_of_range &e)
    {
        // This exception is thrown if the input is out of the range of integers
        std::cerr << "Out of range error: '" << str << "' is out of the range for an integer.\n";
    }

    return -1; // Return -1 in case of an error
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

// 0 >> for exiting the game
// 2 >> for replaying
// 3 >> for change opponent