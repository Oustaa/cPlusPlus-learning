#include <iostream>
using namespace std;

void Reverse(int n)
{
    int rev = 0;
    int m = n;
    int r;

    while (n > 0)
    {
        r = n % 10;
        n /= 10;
        rev = rev * 10 + r;
    }

    cout << rev << endl;
}

int main()
{
    Reverse(123456789);
    return 0;
}