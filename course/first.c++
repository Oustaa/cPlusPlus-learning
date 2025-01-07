#include <iostream>
using namespace std;

int main()
{
    int num1, num2;
    char op; // +, -, /, *

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    cout << "Enter Opperation: ";
    cin >> op;

    switch (op)
    {
    case '+':
        cout << "The of : " << num1 << " + " << num2 << " is " << num1 + num2 << "\n";
        break;

    case '-':
        cout << "The of : " << num1 << " - " << num2 << " is " << num1 - num2 << "\n";
        break;

    case '*':
        cout << "The of : " << num1 << " * " << num2 << " is " << num1 * num2 << "\n";
        break;

    case '/':
        if (num2 == 0)
        {
            cout << "Can't devide by 0 \n";
        }
        else
        {
            cout << "The of : " << num1 << " * " << num2 << " is " << num1 / num2 << "\n";
        }
        break;

    default:
        cout << "entered opperation is unvalid \n";
        break;
    }

    return 0;
}