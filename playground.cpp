#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

#include "./helpers.hpp"

using namespace std;

int string_to_int(char string_int)
{
    return string_int - '0';
}

int main(int argc, char *argv[])
{

    // char answer;
    // cout << "Enter a character: ";
    // cin >> answer;

    // cout << "You entred: " << answer << endl;

    // int myints[] = {10, 20, 30, 40};
    // int *p;

    // p = find(myints, myints + 4, 30);

    // if (p != myints + 4)
    //     cout << "Element found in myints: " << *p << '\n';
    // else
    //     cout << "Element not found in myints\n";

    // char str = '5';
    // try
    // {
    //     int num = stoi(str);

    //     cout << "The integer value is: " << num << endl;
    // }
    // catch (const invalid_argument &e)
    // {
    //     cerr << "Invalid input: Not a valid number." << endl;
    // }
    // catch (const out_of_range &e)
    // {
    //     cerr << "Invalid input: Number out of range." << endl;
    // }

    // cout << string_to_int(str) << endl;
    // int nums[100] = {};

    // for (int i = 0; i < 100; i++)
    // {
    //     nums[i] = i + 1;
    // }

    // logArr(nums, 100);

    // enum
    // {
    //     monday = 1,
    // } days;

    // system("figlet hello");

    // std::cout << 45 % 3 << std::endl;

    // std::string greeting = "Hello";
    // std::string complete_greeting = greeting + " There";
    // complete_greeting += "!";

    // std::cout << complete_greeting << std::endl;
    // std::cout << complete_greeting.length() << std::endl;

    auto x = 5U;

    std::cout << x << std::endl;

    return 0;
}