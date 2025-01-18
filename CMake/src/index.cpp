#include <iostream>

using namespace std;

class Person
{
    string name;
    int age;

public:
    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    string
    get_name()
    {
        return this->name;
    }

    int get_age()
    {
        return this->age;
    }

    friend ostream &operator<<(ostream &o, Person &p);
};

ostream &operator<<(ostream &o, Person &p)
{
    o << p.get_name() << " is " << p.get_age() << endl;
    return o;
}

int main()
{
    return 0;
}