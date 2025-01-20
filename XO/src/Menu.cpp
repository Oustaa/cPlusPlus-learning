#include <iostream>

using namespace std;

namespace Menu
{
    int print_main_menu()
    {
        int choice;

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

    int game_over_menu(string name, char symbol)
    {
        cout << "The winner is (" << symbol << "): " << name << endl;

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

        } while (true);
    }

    string get_player_name_menu_option(char symbol)
    {
        string n;

        cout << "Enter your name (" << symbol << "): ";
        getline(cin, n);

        return n;
    }
};
