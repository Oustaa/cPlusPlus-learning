#include <iostream>

using namespace std;

int main()
{
    // int x = 10;
    // int *p = &x;
    // int **p2 = &p;

    // int hex = 0xfff;

    // cout << "x is: " << x << endl;
    // cout << "p is: " << p << endl;
    // cout << "p2 is: " << p2 << endl;
    // cout << "hex is: " << hex << endl;

    // int A[5] = {1, 2, 3, 4, 5};

    // int *p = new int[5];
    // int *p2;

    // p[0] = 123;

    // cout << p[0] << endl;

    // delete[] p;
    // p = nullptr;
    // cout << *p2 << endl;

    // Dynamic Allocation
    int size;
    cout << "Enter size: ";
    cin >> size;
    int *arrPtr = new int[size];

    arrPtr[0] = 2345;

    cout << "arrPtr before in positoin 0 is " << arrPtr[0] << endl;

    cout << "Enter new size: ";
    cin >> size;

    arrPtr = new int[size];
    cout << "arrPtr after in positoin 0 is " << arrPtr[0] << endl;

    return 0;
}