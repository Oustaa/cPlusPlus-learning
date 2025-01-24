// #include <stdio.h>
#include <iostream>

#define SQRT(arg) ((arg) * (arg))

using namespace std;

constexpr int double_it(int arg) { return arg * arg; }

int main()
{
    cout << SQRT(4) << endl;
    cout << SQRT(4 + 1) << endl;

    int bad_result = double_it(4 + 1);

    cout << bad_result << endl;
    return 0;
}