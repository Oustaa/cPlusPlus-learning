#include <iostream>
#include <limits>
#include <math.h>

// #define PI = 3.1425;

// typedef int marks;
// typedef int roleNumber;

// enum Departements
// {
//     CS = 1,
//     IT = 45,
// };

// typedef struct
// {
//     std::string name;
//     Departements departement;
//     int age;
// } Person;

// float distance(int x1, int y1, int x2, int y2)
// {
//     float dist;

//     dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

//     return dist;
// }

// typedef struct
// {
//     std::string full_name;
//     int age;
// } Person;

// void update(Person *person)
// {
//     person->full_name = "UPDATED";
// }

int main(int argc, const char **argv)
{

    // const char Group = 'a';
    // float Price = 12.75f;
    // double priceMax = 11.99;
    // unsigned long long int num = 1;

    // std::cout << num << std::endl;

    // std::cout << "Maximum value of int: " << std::numeric_limits<int>::max() << std::endl; // 4 bytes => 16 bits
    // std::cout << "Minimum value of int: " << std::numeric_limits<int>::min() << std::endl;
    // std::cout << "Maximum value of long: " << numeric_limits<long>::max() << std::endl;
    // std::cout << "Maximum value of long long: " << numeric_limits<long long>::max() << std::endl;
    // std::cout << "Maximum value of float: " << numeric_limits<float>::max() << std::endl;
    // std::cout << "Maximum value of double: " << numeric_limits<double>::max() << std::endl;

    // std::string name;

    // std::cout << "Enter your name please: ";
    // std::getline(std::cin, name);

    // std::cout << "Hello mr(mrs) " << name << std::endl;

    // Person person = {"Oussama Tailba", 25};

    // std::cout << "NAME BEFORE UPDATE " << person.full_name << std::endl;
    // update(&person);
    // std::cout << "NAME AFTER UPDATE " << person.full_name << std::endl;

    // for (int i = 0; i < argc; i++)
    // {
    //     std::cout << argv[i] << std::endl;
    // }

    // int age;
    // std::cout << "Oussama Tailba, Enter your age: ";
    // std::cin >> age;

    // std::cout << "Your age is " << age << std::endl;

    // char a = 'A', b = 'C', c;

    // c = a % b;

    // std::cout << (int)a << std::endl;
    // std::cout << (int)b << std::endl;
    // std::cout << (1 + 9) * 14 << std::endl;

    // std::cout << std::sqrt(910034) << std::endl;

    // const int age = 26;
    // char x = static_cast<char>(0b10100100);

    // std::cout << (int)x << std::endl;

    // int x = 20, y = 5, z;

    // // z = x & y;
    // // z = x | y;
    // z = x >> 2;

    // std::cout << z << std::endl;

    // Departements dep = CS;

    // if (dep == 1)
    // {
    //     std::cout << "Cloud software" << std::endl;
    // }
    // else if (dep == 45)
    // {
    //     std::cout << "Internet of things" << std::endl;
    // }

    // marks m1, m2, m3;
    // roleNumber r1, r2, r3;

    // Person me = {"Oussama Tailba", IT, 27};

    // std::cout << me.name << std::endl;
    // std::cout << me.departement << std::endl;
    // std::cout << me.age << std::endl;

    // int A[12] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24};
    // int B[] = {};
    std::string names[] = {"Oussama", "kaoutar", "Khadija", "Aziz"};

    // std::cout << A << std::endl;
    // std::cout << B << std::endl;

    // std::cout << "[ ";
    for (auto name : names)
        std::cout << name << std::endl;

    // std::cout << "]\n";

    // std::cout << (float)91 / 22 << std::endl;

    int x = 8;

    std::cout << "x is: " << ++x << std::endl;

    return 0;
}
