#include <iostream>
#include <cstring>
#include <array>

using namespace std;

int main()
{
    // char name[20];

    // cout << "Size of name is: " << sizeof(name) << endl;
    // cout << "Enter your name: ";
    // cin.getline(name, 20);

    // cout << "Your name is: " << name << endl;
    // cout << "Size of name is: " << sizeof(name) << endl;

    // char s[20], s2[20];

    // cout << "Enter your name: ";
    // cin.get(s, 20);
    // cout << "Your enterd " << s << endl;

    // cin.ignore();

    // cout << "Enter your name again: ";
    // cin.get(s2, 20);
    // cout << "Your enterd " << s2 << endl;

    // char name[50];

    // cout << "Enter your name: ";
    // cin.getline(name, 50);

    // cout << "Length of the name you entred is: " << strlen(name) << endl;

    // char s[20] = "Hello";
    // char s2[20] = "HEllO";

    // cout << strcmp(s, s2) << endl;

    // char strnum[10] = "ff";
    // char strfloat[10] = "123.23";

    // long int numstr = strtol(strnum, NULL, 16);
    // float floatstr = strtof(strnum, NULL);

    // cout << "long int: " << numstr << endl;
    // cout << "float: " << floatstr << endl;

    char s1[20] = "x=10;y=10;z=30";

    cout << strtok(s1);

    return 0;
}