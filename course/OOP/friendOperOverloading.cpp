// #include <iostream>

// using namespace std;

// class Complex
// {
// public:
//     int real;
//     int imaginary;

//     Complex(int r, int i)
//     {
//         real = r;
//         imaginary = i;
//     }

//     friend Complex operator+(Complex, Complex);
//     friend ostream &operator<<(ostream &o, Complex &c);
// };

// ostream &operator<<(ostream &o, Complex &c1)
// {
//     string sign = c1.imaginary < 0 ? " - " : " + ";
//     o << c1.real << sign << "i" << abs(c1.imaginary);
//     return o;
// }

// Complex operator+(Complex c1, Complex c2)
// {
//     return Complex(c1.real + c2.real, c1.imaginary + c2.imaginary);
// }

// int main()
// {
//     Complex c1(1, -23), c2(6, 2);

//     Complex c3 = c1 + c2;

//     cout << "c3 = " << c3 << endl;
//     return 0;
// }

#include <iostream>

using namespace std;

class Complex
{
public:
    int real;
    int imaginary;

    Complex(int r, int i)
    {
        this->real = r;
        this->imaginary = i;
    }

    friend Complex operator+(Complex c1, Complex c2);
    friend ostream &operator+(ostream &o, Complex c);
};

Complex operator+(Complex c1, Complex c2)
{
    return Complex(c1.real + c2.real, c1.imaginary + c2.imaginary);
}

ostream &operator<<(ostream &o, Complex c)
{
    string sing = c.imaginary > 0 ? " + " : " - ";
    o << c.real << sing << "i" << abs(c.imaginary);

    return o;
}

int main()
{
    Complex c1(1, -23), c2(6, 2);

    Complex c3 = c1 + c2;

    cout << "c3 = " << c3 << endl;
    return 0;
}