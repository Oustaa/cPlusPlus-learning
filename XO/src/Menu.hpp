#include <iostream>
#include <vector>

using namespace std;

namespace Menu
{
    int print_main_menu()
    {

        int choice;

        // system("clear");
        do
        {
            cout << "Welcome ot the game." << endl;
            cout << "1. Log in" << endl;
            cout << "2. Sign in" << endl;
            cout << "3. Practice" << endl;
            cout << "4. Challenge friend" << endl;
            cout << "5. Quit" << endl;
            cout << "Enter you Choice >> ";

            cin >> choice;

            if (cin.fail())
            {
                cout << "Please enter a valid number!" << endl;

                cin.clear();
                cin.ignore(1000, '\n');
            }

        } while (choice < 1 || choice > 5);

        return choice;
    }

    void player_wins_msg(string name, char symbol)
    {
        cout << "-------------" << endl;
        cout << "The winner is (" << symbol << "): " << name << endl;
        cout << "-------------" << endl;
    }

    int game_over_menu()
    {

        int choice;

        do
        {
            cout << "1. Reply" << endl;
            cout << "2. Change opponent" << endl;
            cout << "3. back" << endl;
            cout << "4.quit" << endl;

            cin >> choice;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(1000, '\n');
            }
        } while (choice < 1 || choice > 4);

        return choice;
    }

    string get_player_name_menu_option(char symbol)
    {
        string n;

        cout << "Enter your name (" << symbol << "): ";
        getline(cin, n);

        return n;
    }

    vector<string> get_players_name()
    {
        vector<string> names;

        cin.ignore();

        string x_player_name = get_player_name_menu_option('x');
        names.push_back(x_player_name);

        string o_player_name = get_player_name_menu_option('o');
        names.push_back(o_player_name);

        cout << "Player X: " << names[0] << ", Player O: " << names[1] << endl;

        return names;
    }

};
