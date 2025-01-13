#include <iostream>

int main()
{
    int i = 1, n;

    std::cout << "Enter n: ";
    std::cin >> n;

    while (i <= n)
    {
        std::cout << i << std::endl;

        i++;
    }

    std::cout << "THIS IS END OF WHILE DO\n";

    i = 1;
    do
    {
        std::cout << i << std::endl;

        i++;
    } while (i <= n);

    return 0;
}