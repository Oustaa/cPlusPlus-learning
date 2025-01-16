#include <iostream>

using namespace std;

#define msg(x) #x

// wrong way of doing callback in c++
// void callback(auto fn)
// {
//     fn();
// }

// might be the correct of doing callback in c++
template <class T>
void callback(T fn)
{
    fn();
}

int main()
{
    // auto f = []()
    // { cout << msg(Hello Oussama Tailba) << endl; };

    // f();
    // f();
    // f();
    // f();
    // f();
    // f();

    // int x = [](int x, int y) -> int
    // { return x + y; }(1, 23);

    // cout << x << endl;

    int a = 23, b = 44;

    // [&]() -> void
    // { cout << a++ << " " << ++b << endl; }();

    // cout << a << " " << b << endl;

    auto fn = [a, b]() -> void
    { cout << a << " " << b << endl; };

    callback(fn);
    callback([]()
             { cout << "I love C++" << endl; });

    return 0;
}