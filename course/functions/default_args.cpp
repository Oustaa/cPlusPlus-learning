#include <iostream>
#include <string>

using namespace std;

template <class T>
T maximum(T x, T y, bool log = true)
{
    T m = x > y ? x : y;

    if (log == true)
    {
        cout << "from fucntion " << m << endl;
    }

    return m;
}

int main()
{
    int m = maximum(1, 23, false);

    cout << m << endl;
    return 0;
}
