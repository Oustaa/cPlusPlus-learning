#include <iostream>

using namespace std;

class Person
{
private:
    string name;

public:
    Person(string name)
    {
        this->name = name;
    }

    string get_name()
    {
        return this->name;
    }

    void set_name(string name)
    {
        this->name = name;
    }
};

int main()
{
    Person oussama("Oussama");

    cout << oussama.get_name() << endl;

    oussama.set_name("Kaoutar");

    cout << oussama.get_name() << endl;

    return 0;
}