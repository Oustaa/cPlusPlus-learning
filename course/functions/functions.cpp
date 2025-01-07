#include <iostream>
#include <string>

using namespace std;

int add(int a, int b)
{
    return a + b;
}

float add(float a, float b)
{
    return a + b;
}

int main()
{
    int intSum = add(1, 2);
    float floatSum = add(1.23f, 2.12f);

    cout << intSum << endl;
    cout << floatSum << endl;

    return 1;
}