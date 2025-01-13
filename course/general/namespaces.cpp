#include <iostream>
#include "./namespaces.h"

using namespace std;
using namespace First;

int main()
{
    First::fun();
    Second::fun();
    fun();

    return 0;
}