#include <iostream>
#include <string>

using namespace std;

template <class T>
T maximum(T x, T y)
{
    return x > y ? x : y;
}

int main()
{
    int m = maximum(1, 23);

    cout << m << endl;
    return 0;
}