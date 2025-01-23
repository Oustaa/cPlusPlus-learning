#include <iostream>
#include <vector>
#include <mutex>
#include <algorithm>

using namespace std;

class Game
{
    static Game *game_ptr;
    static mutex mtx;
    bool game_over = false;
    vector<int[]> *win_paterns;
    vector<Player> players;
    vector<int> played_spots;
    char played_spots_plac_holder[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int player_turn = 0;
    int play_gount = 0;

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

    void print_map(char map_place_holders[9])
    {
        int played_spot;
        // system("clear");

        // cout << "+++++++++++++" << endl;
        // cout << "| X | T | O |" << endl;
        // cout << "+++++++++++++" << endl;
        // cout << "| 0 | 0 | 0 |" << endl;
        // cout << "+++++++++++++" << endl;
        cout << "-------------" << endl;
        for (int i = 1; i <= 9; i++)
        {
            cout << "| " << map_place_holders[i - 1] << " ";

            if (i % 3 == 0)
            {
                cout << "|" << endl;
                cout << "-------------" << endl;
            }
        }
    }

    int get_player_spot()
    {
        int played_spot;

        do
        {
            cout << players[player_turn].name << " chose a spot (" << players[player_turn].symbol << "): ";
            cin >> played_spot;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(1000, '\n');
            }

            if (played_spot < 1 || played_spot > 9 || find(played_spots.begin(), played_spots.end(), played_spot) != played_spots.end())
                cout << "invalid input!!!!!!" << endl;
            else
                break;

        } while (true);

        return played_spot;
    }

    void start_game()
    {
        vector<string> players_names = Menu::get_players_name();

        players.clear();
        players.push_back(Player(players_names[0], 'x'));
        players.push_back(Player(players_names[1], 'o'));

        while (!game_over)
        {
            play_gount++;
            // Player current_player = players[player_turn];
            print_map(played_spots_plac_holder);
            // get current player played spot
            int played_on = get_player_spot();

            played_spots_plac_holder[played_on - 1] = players[player_turn].symbol;
            played_spots.push_back(played_on);
            players[player_turn].play(played_on);

            if (play_gount >= 5)
            {
                if (players[player_turn].check_wins())
                {
                    Menu::game_over_menu(players[player_turn].name, players[player_turn].symbol);
                }
            }

            player_turn = player_turn == 0 ? 1 : 0;
        }
    }
};

Game *Game::game_ptr = nullptr;
mutex Game::mtx;
