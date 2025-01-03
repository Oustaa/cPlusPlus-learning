#include <iostream>

using namespace std;

class Vehicule
{
    static const int counter;

public:
    string brand;
    int releas_year;

    Vehicule()
    {
        counter += 1;
    }
};

class Car : public Vehicule
{
};

ostream &operator<<(ostream &o, Vehicule v)
{
    o << v.brand << " was realsed on " << v.releas_year;
    return o;
}

int main()
{
    Vehicule v;
    v.brand = "Car";
    v.releas_year = 1998;

    Car c;
    c.brand = "Toyota";
    c.releas_year = 1998;

    cout << c << endl;
    cout << v << endl;

    return 0;
}