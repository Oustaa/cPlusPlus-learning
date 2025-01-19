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
                continue;
            }

        } while (choice < 1 || choice > 5);

        return choice;
    }
};
