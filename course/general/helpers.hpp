#include <iostream>

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