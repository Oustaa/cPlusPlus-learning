#include <iostream>
#include <typeinfo>

bool checkAge(int age)
{
    return age > 18;
}

int main()
{
    // std::cout << "Type of x: " << typeid(0.234f).name() << std::endl;

    // if (0.23f)
    // {
    //     std::cout << "True True" << std::endl;
    // }
    int age;
    std::cout << "Enter you age: ";
    std::cin >> age;

    if (bool checked = checkAge(age); checked == true)
    {
        std::cout << "Hello, you are eligible" << std::endl;
    }
    else
    {
        std::cout << "Hello, you are not eligible" << std::endl;
    }

    return 0;
}