#include <iostream>
#include <algorithm> // For std::find

int main()
{
    // Declare and initialize an array of integers with values from 1 to 9
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    // // The size of the array
    int arraySize = sizeof(numbers) / sizeof(numbers[0]);

    // The number to check for
    int target = 52;

    // Use std::find to search for the target in the array
    if (std::find(numbers, numbers + arraySize, target) != numbers + arraySize)
    {
        std::cout << target << " is in the array." << std::endl;
    }
    else
    {
        std::cout << target << " is not in the array." << std::endl;
    }

    // std::cout << numbers[20] << std::endl;

    return 0;
}
