#include <iostream>
#include <math.h>

int main()
{
    float radius, area;

    std::cout << "enter the circel radius: ";
    std::cin >> radius;

    area = 3.1425 * std::pow(radius, 2);

    std::cout << "The circel area is " << area << std::endl;

    return 0;
}