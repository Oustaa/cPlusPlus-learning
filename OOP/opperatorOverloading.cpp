#include <iostream>
#include <cmath>

using namespace std;

class Complex
{
private:
    int real;
    int imaginary;

public:
    Complex(int r = 0, int i = 0)
    {
        real = r;
        imaginary = i;
    }

    int get_real()
    {
        return this->real;
    }

    int get_imaginary()
    {
        return this->imaginary;
    }

    Complex operator+(Complex c)
    {

        return Complex(c.real + real, c.imaginary + imaginary);
    }

    Complex operator-(Complex c)
    {

        return Complex(c.real - real, c.imaginary - imaginary);
    }

    void log(string name)
    {
        string sign = imaginary < 0 ? " - " : " + ";
        cout << name << " = " << real << sign << abs(imaginary) << "i" << endl;
    }
};

int main()
{
    Complex c1(1, 3412);
    Complex c2(11, 34);
    Complex c3 = c1 + c2;
    Complex c4 = c1 - c2;

    c1.log("c1");
    c2.log("c2");
    c3.log("c3");
    c4.log("c4");

    cout << sqrt(81) << endl;

    return 0;
}