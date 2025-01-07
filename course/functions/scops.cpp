#include <iostream>

using namespace std;

int x = 100;

int main()
{
    cout << x << endl;

    int x = 1234;

    {
        int x = 4321;
        cout << ::x << endl;
    }

    cout << ::x << endl;
}