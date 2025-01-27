#include <iostream>
#include <vector>

using namespace std;

class Player
{
public:
    virtual int play()
    {
        cout << "Player's play function" << endl;
        return 1;
    }
};

class Computer : public Player
{
public:
    int play() override
    {
        cout << "Computer's play function" << endl;
        return 1;
    }
};

int main()
{
    // vector<int> played_spots;

    // played_spots.push_back(1);
    // played_spots.push_back(2);
    // played_spots.push_back(3);

    // for (int played_spot : played_spots)
    // {
    //     cout << played_spot << endl;
    // }

    // char played_spots[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

    // for (char ch : played_spots)
    // {
    //     cout << ch << endl;
    // }

    Player player;
    Player computer = Computer();

    player.play();
    computer.play();

    return 0;
}