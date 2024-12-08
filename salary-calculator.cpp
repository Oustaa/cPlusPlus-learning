#include <iostream>
#include <math.h>

int main()
{
    float basicSalary, salary, percentDedaction, percentAllowances;

    std::cout << "enter you basic salary: ";
    std::cin >> basicSalary;

    std::cout << "enter you percent dedaction: ";
    std::cin >> percentDedaction;

    std::cout << "enter you percent allowances: ";
    std::cin >> percentAllowances;

    salary = basicSalary + basicSalary * percentAllowances / 100 - basicSalary * percentDedaction / 100;

    std::cout << "Your net salary is " << salary << std::endl;

    return 0;
}