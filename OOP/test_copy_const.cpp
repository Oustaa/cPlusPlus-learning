#include <iostream>

using namespace std;

class Test
{
public:
    int a;
    int *p;
    Test(int x)
    {
        a = x;
        p = new int[a];
    }

    Test(const Test &t)
    {
        a = t.a;
        p = new int[a];
        for (int i = 0; i < a; i++)
            p[i] = t.p[i];
    }

    ~Test()
    {
        delete[] p;
    }
};

void log_test(const Test t, int length)
{
    cout << "[ ";
    for (int i = 0; i < length; i++)
    {

        cout << t.p[i];
        if (i < length - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main()
{
    int a = 3;

    Test t(a);
    Test t2(t);

    for (int i = 0; i < a; i++)
    {
        t.p[i] = i + 1;
    }

    log_test(t, a);

    t.p[1] = 234;

    log_test(t, a);
    log_test(t2, a);

    return 0;
}
