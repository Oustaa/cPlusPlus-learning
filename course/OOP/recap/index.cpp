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

    string get_name()
    {
        return name;
    }

    friend ostream &operator<<(ostream &o, Person p);
};

ostream &operator<<(ostream &o, Person p)
{
    o << p.name << " is " << p.age << endl;

    return o;
}

void test()
{
    static int counter = 0;

    counter++;

    cout << counter << endl;
}

int main()
{
    Person oussama("Oussama Tailba", 26);

    cout << oussama;

    cout << oussama.get_name() << endl;

    test();
    test();
    test();
    test();
    test();
    test();

    return 0;
}