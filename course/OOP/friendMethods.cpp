#include <iostream>

using namespace std;

class Your;

class Me
{
private:
    int a;

protected:
    int b;
    static int count;

public:
    int c;

    Me()
    {
        count++;
        cout << "Me Constructor called " << count << endl;
    }

    static int getCount()
    {
        return count;
    }

    static void printCount()
    {
        cout << count << endl;
    }

    friend ostream &operator<<(ostream &out, const Me &m);
    friend Me fun();
    friend Your;
};

int Me::count = 0;

class Your
{
    Me me;

    void fun()
    {
        cout << me.a << endl;
        cout << me.b << endl;
        cout << me.c << endl;
    }
};

ostream &
operator<<(ostream &out, const Me &m)
{
    cout << m.a << " " << m.b << " " << m.c << endl;

    return out;
}

Me fun()
{
    Me me;
    me.a = 10;
    me.b = 20;
    me.c = 30;
    return me;
}

int main()
{
    Me me = fun();
    // this line instantiates 10 objects of Me
    Me myMes[10];

    cout << me;

    cout << Me::getCount() << endl;

    return 0;
}