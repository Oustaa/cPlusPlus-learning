#include <iostream>

int test_me(int, int);

int main()
{
    int x = 30;
    // std::cout << std::hex << x << std::endl;

    std::cout << std::hex << test_me(122, 23) << std::endl;

    return 1;
}

int test_me(int l, int h)
{
    return l + h;
}