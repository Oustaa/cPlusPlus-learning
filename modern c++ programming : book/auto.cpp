#include <iostream>

using namespace std;
using llong = long long;

class Foo
{
    int x;

public:
    Foo(const int x = 0)
    {
        this->x = x;
    }

    int &get_x()
    {
        return x;
    }
};

int main()
{

    Foo f(42);

    auto &x = f.get_x();

    auto name = "Oussam Tailba"s;

    x = 20000;

    std::cout << f.get_x() << std::endl;

    auto ll1 = (long long){23};

    auto ll2 = llong{23};

    return 0;
}