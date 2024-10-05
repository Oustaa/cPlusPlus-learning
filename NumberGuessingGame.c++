#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(0));
    int randomNumber = rand() % 101;
    int playerGuess, numberOfTries = 0, allowedTries = 5;

    while (true)
    {
        numberOfTries++;
        std::cout << "Enter you guess: ";
        std::cin >> playerGuess;

        if (numberOfTries == allowedTries)
        {
            std::cout << "You could not find the number after 5 tries" << std::endl;
            break;
        }

        if (playerGuess == randomNumber)
        {
            std::cout << "You have found the number with " << numberOfTries << " tries" << std::endl;
            break;
        }
        else if (playerGuess < randomNumber)
        {
            std::cout << "Try a BIGGER number" << std::endl;
        }
        else
        {
            std::cout << "Try a SMALLER number" << std::endl;
        }
    }

    return 0;
}
