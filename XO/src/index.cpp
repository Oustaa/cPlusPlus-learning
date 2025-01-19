#include <iostream>

#include "Menu.cpp"
#include "Player.cpp"
#include "Game.cpp"

using namespace std;

int main()
{
    // string name;

    // getline(cin, name);

    // Player player(name);

    // cout << player.player_name << endl;

    int user_choice = Menu::print_main_menu();

    cout << "You choce: " << user_choice << endl;

    return 0;
}