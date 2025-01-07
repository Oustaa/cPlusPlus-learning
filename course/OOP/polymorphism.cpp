#include <iostream>

using namespace std;

class Car
{
public:
    virtual void start() = 0;
    virtual void stop() = 0;
};

class GLE : public Car
{

public:
    void start()
    {
        cout << "My GLE Just Started" << endl;
    }

    void stop()
    {
        cout << "My GLE Just Stoped" << endl;
    }
};

int main()
{
    // GLE mine;

    // mine.start();

    Car car;

    return 0;
}