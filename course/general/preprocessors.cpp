#include <iostream>

using namespace std;

#define MSG(x) #x

#ifndef SQR
#define SQR(x) (x + x)
#endif

#define SQR(x) (x * x)

int main()
{
    cout << MSG(Oussama is a C++ developer) << endl;
    cout << SQR(5) << endl;

    return 0;
}