#include <iostream>
#include <vector>
#include <mutex>

#include "Player.cpp"
#include "Menu.cpp"

using namespace std;

class Game
{

    static Game *game_ptr;
    static mutex mtx;

    vector<Player> players;

    Game() {}

    Game(const Game &) = delete;
    Game &operator=(const Game &) = delete;

public:
    static Game *getInstance()
    {
        if (game_ptr == nullptr)
        {
            lock_guard<mutex> lock(mtx);
            if (game_ptr == nullptr)
            {
                game_ptr = new Game();
            }
        }
        return game_ptr;
    }

    void set_players(vector<Player> players) const
    {
        Game::game_ptr->players = players;
    }
};

Game *Game::game_ptr = nullptr;
mutex Game::mtx;

int main()
{
    Game *game = Game::getInstance();
    vector<Player> players;

    string x_player_name = Menu::get_player_name_menu_option('X');
    players.push_back(Player(x_player_name));
    string o_player_name = Menu::get_player_name_menu_option('O');
    players.push_back(Player(o_player_name));

    Player player("Oussama Tailba");

    game->set_players(players);
}