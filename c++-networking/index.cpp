#include <iostream>

int main()
{

    char *message;

    std::cout << "Enter your message: ";
    std::cin.getline(message, 1000);

    std::cout << message << std::endl;

    return 0;
}
