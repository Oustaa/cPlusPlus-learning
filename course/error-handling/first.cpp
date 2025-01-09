#include <iostream>

using namespace std;

enum ErrorCode
{
    DIVISION_BY_ZERO,
    UNVALID_PARAMS
};

class MyError : public exception
{
public:
    ErrorCode error_code;
    string error_message;

    MyError(ErrorCode code, string message)
    {
        error_code = code;
        error_message = message;
    }

    string what()
    {
        return "My Own Error";
    }
};

int division(int a, int b) noexcept(false)
{
    if (b == 0)
        throw 1;
    // throw MyError(2, "Division by ZERO");
    return a / b;
}

int main()
{
    int a = 12, b = 0, c;
    try
    {
        if (b == 0)
            throw MyError(UNVALID_PARAMS, "Division by ZERO");
        // throw "Div By Zero";
        c = a / b;
        cout << c << endl;
    }
    catch (MyError e)
    // catch (string e)
    {
        // cout << e << endl;

        // cout << e.error_message << endl;
        // cout << e.error_code << endl;

        switch (e.error_code)
        {
        case DIVISION_BY_ZERO:
            cout << "Division by" << endl;
            break;

        case UNVALID_PARAMS:
            cout << "rwah t9owed" << endl;
            break;

        default:
            break;
        }
    }

    return 0;
}