#include <iostream>

struct BeforeMain
{
    BeforeMain()
    {
        std::cout << "Constructing BeforeMain" << std::endl;
    }

    void test()
    {
        std::cout << "Hello orld" << std::endl;
    }
};

BeforeMain b;

int main()
{

    std::cout << "Calling main()" << std::endl;

    return 0;
}