#include <iostream>
#include <cstdarg>

using namespace std;

template <class T>
T sum(int n, ...)
{
    va_list args_list;
    va_start(args_list, n);

    T s = 0;

    for (int i = 0; i < n; i++)
        s += va_arg(args_list, T);

    va_end(args_list);

    return s;
}

int main()
{

    int totali = sum<int>(4, 235, 453, 712);
    double totalf = sum<double>(4, 235.23, 453.99, 712.85);

    cout << totali << endl;
    cout << totalf << endl;

    return 0;
}