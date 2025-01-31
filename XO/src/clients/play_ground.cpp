#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

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

    // Player player;
    // Player computer = Computer();

    // player.play();
    // computer.play();

    // vector<Player *> players_ptrs;

    // players_ptrs.push_back(new Player());
    // players_ptrs.push_back(new Player());
    // players_ptrs.push_back(new Player());
    // players_ptrs.push_back(new Player());

    // for (auto player : players_ptrs)
    // {
    //     player->play();
    // }

    // vector<int> played_spots = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> available_spots = {5, 7};

    // // Create random device and generator (do this once)
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, available_spots.size() - 1);

    // // Get random number betweall_played_spotsen 1 and 9
    int random_index = dist(gen);

    cout << available_spots[random_index] << endl;

    // vector<int> available_spots = {1, 2, 3, 4, 5, 6, 7, 8, 9, 322};

    // vector<int>::iterator it = find(available_spots.begin(), available_spots.end(), 1);

    // if (it == available_spots.end())
    //     cout << "not found\n";
    // else
    //     cout << "found at index: " << it - available_spots.begin() << endl;

    // cout << available_spots.size() << endl;

    return 0;
}
#include <vector>
