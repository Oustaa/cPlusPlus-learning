#include <iostream>
#include <vector>
#include <map>

using namespace std;

using byte = unsigned char;
using byte_ptr = unsigned char *;

struct Product
{
    string title;
    double price;
};

class Foo
{
public:
    int a_;
    double b_;

    Foo() : a_(0), b_(0) {}
    Foo(int a, double b = 0.0) : a_(a), b_(b)
    {
        cout << "Foo parametrized constructor was called" << endl;
    }
};

class Foo2
{

public:
    int a_;
    Foo2(int a) : a_(a) {}
};

int main()
{
    vector<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9};
    map<int, Product> product_collection;

    Foo foo{12, 344.3};

    cout << foo.a_ << " " << foo.b_ << endl;

    Foo2 f1 = 42;

    cout << f1.a_ << endl;

    return 0;
}