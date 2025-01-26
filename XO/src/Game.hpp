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
    vector<char> played_spots_plac_holder = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int player_turn = 0;
    int play_count = 0;
    bool player_wins = false;
    int ties = 0;

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

    void restart_game()
    {

        if (!player_wins)
        {
            player_turn = player_turn == 0 ? 1 : 0;
        }
        play_count = 0;
        game_over = false;
        played_spots.clear();
        played_spots_plac_holder = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        for (Player &player : players)
        {
            player.clear();
        }
    }

    void print_map(vector<char> map_place_holders)
    {
        int played_spot;
        system("clear");

        cout << "+++++++++++++" << endl;
        cout << "| X | T | O |" << endl;
        cout << "+++++++++++++" << endl;
        cout << "| " << players[0].get_score().wins << " | " << ties << " | " << players[1].get_score().wins << " | " << endl;
        cout << "+++++++++++++" << endl;
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
        Player *current_player_ptr;
        vector<string> players_names = Menu::get_players_name();

        players.clear();
        players.push_back(Player(players_names[0], 'x'));
        players.push_back(Player(players_names[1], 'o'));

        while (true)
        {
            while (!game_over)
            {

                current_player_ptr = &players[player_turn];
                play_count++;
                // Player current_player = players[player_turn];
                print_map(played_spots_plac_holder);
                // get current player played spot
                int played_on = get_player_spot();

                played_spots_plac_holder[played_on - 1] = current_player_ptr->symbol;
                played_spots.push_back(played_on);
                current_player_ptr->play(played_on);

                if (play_count >= 5)
                {
                    if (current_player_ptr->check_wins())
                    {
                        Menu::player_wins_msg(current_player_ptr->name, current_player_ptr->symbol);
                        player_wins = true;
                        break;
                    }
                }

                if (play_count == 9)
                {
                    ties++;
                    cout << "You tied." << endl;
                    break;
                }

                player_turn = player_turn == 0 ? 1 : 0;
            }

            int choice = Menu::game_over_menu();
            switch (choice)
            {
            case 1:
                restart_game();
                break;
            case 4:
                return;

            default:
                break;
            }
        }
    }
};

Game *Game::game_ptr = nullptr;
mutex Game::mtx;
