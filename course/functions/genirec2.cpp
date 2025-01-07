#include <iostream>

using namespace std;

template <class T>
T sum(T a, T b)
{
    return a + b;
}

int main()
{
    int result1 = sum(1, 234);
    float result2 = sum(1.12f, 23.23f);

    cout << result1 << endl;
    cout << result2 << endl;

    return 0;
}