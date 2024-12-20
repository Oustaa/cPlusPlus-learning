#include <iostream>

using namespace std;

struct Player
{
    string name = "Oussama";
};

int g = 100;

int *init_arr_by_size(int size);

int main()
{
    int *arr = init_arr_by_size(34);

    cout << endl;
    cout << endl;
}

int *init_arr_by_size(int size)
{
    int *p = new int[size];

    for (int i = 0; i < size; i++)
        p[i] = i;

    cout << "g = " << g << endl;

    return p;
}