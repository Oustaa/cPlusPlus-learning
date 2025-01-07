#include <iostream>

using namespace std;

void display(string name)
{
    cout << "Hello " << name << endl;
}

void call_me_back(string name, void (*cb)(string name))
{
    (*cb)(name);
}

int main()
{
    void (*cb)(string name);

    cb = display;

    call_me_back("Oussama", cb);
    call_me_back("Kaoutar", cb);
}
