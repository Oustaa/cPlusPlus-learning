#include <iostream>

using namespace std;

int main()
{
    char played_spots[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

    for (char ch : played_spots)
    {
        cout << ch << endl;
    }

    return 0;
}