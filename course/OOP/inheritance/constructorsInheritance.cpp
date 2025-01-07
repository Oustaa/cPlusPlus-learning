#include <iostream>

using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Default of Base class" << endl;
    }

    Base(int x)
    {
        cout << "Params of Base class " << x << endl;
    }
};

class Base2
{
public:
    Base2()
    {
        cout << "Default of Base2 class" << endl;
    }

    Base2(int x)
    {
        cout << "Params of Base2 class " << x << endl;
    }
};

class Derived : public Base, Base2
{
public:
    Derived()
    {
        cout << "Default of Derived class" << endl;
    }

    Derived(int x)
    {
        cout << "Params of Derived class " << x << endl;
    }

    Derived(int x, int a) : Base(x)
    {
        cout << "Params of Derived class " << x << endl;
    }
};

// template <class T>
// T mine(T x, T y)
// {
//     return x + y;
// }

int main()
{
    // Base b1;

    // double result = mine(12.2, 23.3);

    // cout << result << endl;

    Derived d1;
    Base b2(12);
    Derived d12(23);

    // bool isBase = isBase, b1;

    // cout << isBase;
}