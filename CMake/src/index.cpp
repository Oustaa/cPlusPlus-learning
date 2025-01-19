#include <iostream>

#include "TutorialConfig.h"

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

int main(int argc, char **argv)
{
    // Person me("Oussama Tailba", 27);

    // cout << me;

    if (argc < 2)
    {
        // report version
        std::cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR << "."
                  << Tutorial_VERSION_MINOR << std::endl;
        std::cout << "Usage: " << argv[0] << " number" << std::endl;
        return 1;
    }

    return 0;
}