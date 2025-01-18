#include <iostream>
using namespace std;

int Reverse(int n)
{
    int rev = 0;
    int r;

    while (n > 0)
    {
        r = n % 10;
        n /= 10;
        rev = rev * 10 + r;
    }

    return rev;
}

int main()
{
    // int day = 1;
    // int day(1);
    // int day = (1);
    // int day{1};
    // int day = {1};

    int _roll_num = 120;
    cout << Reverse(123456789) << endl;

    return 0;
}