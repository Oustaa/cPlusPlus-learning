#include <iostream>

class Car
{
public:
    int releas_year;
    std::string brand;

    virtual void start() = 0;
    virtual void stop() = 0;
};

class GLE : public Car
{
public:
    GLE()
    {
        brand = "MERCEDES";
        releas_year = 2025;
    }

    void start() override
    {
        std::cout << brand << " starting, release year: " << releas_year << std::endl;
    }

    void stop() override
    {
        std::cout << brand << " stopping" << std::endl;
    }
};

class Demo
{
public:
    Demo()
    {
        std::cout << "Constractore of Demo" << std::endl;
    }

    ~Demo()
    {

        std::cout << "Destractore of Demo" << std::endl;
    }
};

Demo *fun()
{
    Demo *d = new Demo();

    return d;
}

int main()
{

    Demo *d = fun();

    delete d;
    GLE *myCarPtr = new GLE();
    myCarPtr->start();
    myCarPtr->stop();

    return 0;
}