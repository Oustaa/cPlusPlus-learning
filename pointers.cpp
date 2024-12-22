// #include <iostream>

// using namespace std;

// void fun(int *q);

// int main()
// {
//     // int x = 10;
//     // int *p = &x;
//     // int **p2 = &p;

//     // int hex = 0xfff;

//     // cout << "x is: " << x << endl;
//     // cout << "p is: " << p << endl;
//     // cout << "p2 is: " << p2 << endl;
//     // cout << "hex is: " << hex << endl;

//     // int A[5] = {1, 2, 3, 4, 5};

//     // int *p = new int[5];
//     // int *p2;

//     // p[0] = 123;

//     // cout << p[0] << endl;

//     // delete[] p;
//     // p = nullptr;
//     // cout << *p2 << endl;

//     // Dynamic Allocation
//     // int size;
//     // cout << "Enter size: ";
//     // cin >> size;
//     // int *arrPtr = new int[size];

//     // arrPtr[0] = 2345;

//     // cout << "arrPtr before in positoin 0 is " << arrPtr[0] << endl;

//     // cout << "Enter new size: ";
//     // cin >> size;

//     // arrPtr = new int[size];
//     // cout << "arrPtr after in positoin 0 is " << arrPtr[0] << endl;
//     // int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     // int *p = arr, *q = &arr[3];

//     // p = p - 2;

//     // std::cout << p << std::endl;
//     // std::cout << p[10] << std::endl;

//     // int *p;
//     // *p = (int)0x7ffe79438500;

//     // std::cout << *p << std::endl;

//     // int *arrHeap = new int[5];

//     // arrHeap[0] = 2345;

//     // std::cout << arrHeap[0] << std::endl;
//     // delete arrHeap;
//     // arrHeap = nullptr;
//     // // std::cout << arrHeap[0] << std::endl;

//     // int *arrHeap = new int[5];
//     // arrHeap[0] = 7;

//     // std::cout << *arrHeap << std::endl;
//     // fun(arrHeap);
//     // std::cout << *arrHeap << std::endl;

//     int x = 10;

//     int &y = x;

//     y = 100;

//     cout << "x= " << x << endl;
//     cout << "y= " << y << endl;

//     return 0;
// }

// // void fun(int *q)
// // {
// //     delete[] q;
// // }

#include <iostream>
using namespace std;

int main()
{
    int num = 90;
    int *p = &num;

    cout << num << endl;
    cout << &num << endl;
    cout << **&p << endl;

    return 0;
}
