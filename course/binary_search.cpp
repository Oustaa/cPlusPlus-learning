#include <iostream>

int binarySearch(int arr[10], int arrLen, int key);

int main()
{
    int twoDArr[2][2] = {1, 2, 2, 3};

    std::cout << "before modif: " << twoDArr[1][1] << std::endl;
    twoDArr[1][1] = 23455;
    std::cout << "after modif: " << twoDArr[1][1] << std::endl;

    int arr[10] = {6, 8, 13, 17, 20, 22, 25, 28, 30, 35};
    int key = 25, keyIndex = -1;

    // for (int i = 0; i < 9; i++)
    // {
    //     if (arr[i] == key)
    //     {
    //         keyIndex = i;
    //         break;
    //     }
    // }

    std::cout << key << " found in index " << binarySearch(arr, 10, key) << std::endl;

    return 0;
}

int binarySearch(int arr[10], int arrLen, int key)
{
    int start = 0, end = arrLen;

    while (start < end)
    {
        int middle = (start + end) / 2;

        std::cout << "middle " << middle << std::endl;

        if (arr[middle] == key)
        {
            return middle;
        }
        else if (arr[middle] > key)
        {
            end = middle - 1;
        }
        else
        {
            start = middle + 1;
        }
    }

    return -1;
}