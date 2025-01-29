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

void game_with_friend(Game *game)
{
    vector<string> players_names = Menu::get_players_name();

    HumanPlayer xplayer(players_names[0], 'x');
    HumanPlayer oplayer(players_names[1], 'o');

    game->start_game(xplayer, oplayer);
}

void game_with_computer(Game *game)
{
    cin.ignore();
    string xPlayer_name = Menu::get_player_name_menu_option('x');

    HumanPlayer xplayer = HumanPlayer(xPlayer_name, 'x');
    Computer computer = Computer('o');

    game->start_game(xplayer, computer);
}

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
            game_with_computer(game);
            break;
        case 4:
            game_with_friend(game);
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
