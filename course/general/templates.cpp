#include <iostream>

using namespace std;

#define name "Oussama";

template <class T, class G>
class Max
{
public:
    T prop1;
    G prop2;

    Max(T arg1, T arg2, G arg3)
    {

        prop1 = arg1 + arg2;
        prop2 = arg3;
    }
};

template <class T>
class Stack
{
    T s[0];
    int top;

public:
    void push(T item);
    T pop();
};

template <class T>
void Stack<T>::push(T item)
{
    s[top] = item;
}

template <class T>
T Stack<T>::pop()
{
    return s[0];
}

int _max(const long int &x, const long int &y)
{
    // x = 123435454;

    return x > y ? x : y;
}

int main()
{
    long int x = 23, y = 4566;
    Max max(23.3f, 34.56f, "Oussama");
    Max max2(string("Oussama "), string("tailba"), 234);

    cout << "prop1 " << max.prop1 << ", prop2 " << max.prop2 << endl;
    cout << "prop1 " << max2.prop1 << ", prop2 " << max2.prop2 << endl;

    cout << _max(x, y) << endl;

    name += " is the goat";

    cout << name;

    return 0;
}
