#include <iostream>

using namespace std;

class Test
{
public:
    int x = 90;
    int y = 60;

    Test(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    Test() : Test(1, 1)
    {
    }
};

int main()
{

    Test mine(1, 23);
    Test mine2;

    cout << mine.x << ", " << mine.y << endl;
    cout << mine2.x << ", " << mine2.y << endl;

    return 0;
}