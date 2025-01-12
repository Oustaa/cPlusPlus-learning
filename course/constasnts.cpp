#include <iostream>

using namespace std;

// class Demo
// {
// public:
//     int x = 10;
//     int y = 20;

//     void display() const
//     {
//         x++;
//         cout << x << " " << y << endl;
//     }
// };

void fun(const int &x, const int &y)
{
    cout << x << " " << y << endl;
}

int main()
{
    int x = 30, y = 300;

    fun(x, y);

    const int *const ptr = &x;
    // ptr = &y;

    // *ptr += 45;

    cout << *ptr << endl;

    // ++(*ptr);

    return 0;
}