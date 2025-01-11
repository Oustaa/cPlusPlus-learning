#include <iostream>

using namespace std;

namespace First
{
    void fun()
    {
        cout << "First fun" << endl;
    }
}

namespace Second
{
    void fun()
    {
        cout << "Second fun" << endl;
    }
}

int main()
{
    First::fun();
    Second::fun();

    return 0;
}