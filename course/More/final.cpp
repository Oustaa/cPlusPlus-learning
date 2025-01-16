#include <iostream>

using namespace std;

// class Parent final
class Parent
{

    virtual int fun() final
    {
        return 120;
    }
};

class Child : public Parent
{
    // void fun() {}
};

int main()
{

    return 0;
}