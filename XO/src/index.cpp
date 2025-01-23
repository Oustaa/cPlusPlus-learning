#include <iostream>
#include <vector>

#include "Menu.hpp"
#include "Player.hpp"
#include "Game.hpp"

#if __has_include("utils.hpp")
#else
#include "utils.hpp"
#endif

using namespace std;

struct Players
{
    Player x_player;
    Player o_player;
};

int main()
{

    bool running = true;
    int user_choice;

    Game *game = Game::getInstance();

    do
    {
        user_choice = Menu::print_main_menu();
        cout << "-----------------------" << endl;

        switch (user_choice)
        {
        case 1:
            cout << "Log in form" << endl;
            break;
        case 2:
            cout << "Sign in form" << endl;
            break;
        case 3:
            cout << "Play with cpu = Practice" << endl;
            break;
        case 4:
            game->start_game();
            break;
        case 5:
            cout << "Goodbye, you will be missed <3" << endl;
            running = false;
            break;
        }
        cout << "-----------------------" << endl;
    } while (running);

    return 0;
}
