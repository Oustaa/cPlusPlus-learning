#include <iostream>

using namespace std;

class Base
{
public:
    virtual void display()
    {
        cout << "Display from Base" << endl;
    }
};

class Derived : public Base
{
public:
    string name = "Oussama Tailba";
    void display()
    {
        cout << "Display from Derived" << endl;
    }
};

int main()
{
    Derived d;

    d.Base::display();

    cout << d.name << endl;

    Base *bp = new Derived();

    bp->display();

    return 0;
}