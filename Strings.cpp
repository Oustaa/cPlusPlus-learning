// #include <iostream>
// #include <string>

// using namespace std;

// int main()
// {
//     // char name[20];

//     // cout << "Size of name is: " << sizeof(name) << endl;
//     // cout << "Enter your name: ";
//     // cin.getline(name, 20);

//     // cout << "Your name is: " << name << endl;
//     // cout << "Size of name is: " << sizeof(name) << endl;

//     // char s[20], s2[20];

//     // cout << "Enter your name: ";
//     // cin.get(s, 20);
//     // cout << "Your enterd " << s << endl;

//     // cin.ignore();

//     // cout << "Enter your name again: ";
//     // cin.get(s2, 20);    cout << copy << endl;

//     // cout << "Your enterd " << s2 << endl;

//     // char name[50];

//     // cout << "Enter your name: ";
//     // cin.getline(name, 50);

//     // cout << "Length of the name you entred is: " << strlen(name) << endl;

//     // char s[20] = "Hello";
//     // char s2[20] = "HEllO";

//     // cout << strcmp(s, s2) << endl;

//     // char strnum[10] = "ff";
//     // char strfloat[10] = "123.23";

//     // long int numstr = strtol(strnum, NULL, 16);
//     // float floatstr = strtof(strnum, NULL);

//     // cout << "long int: " << numstr << endl;
//     // cout << "float: " << floatstr << endl;

//     // char s1[20] = "x=10;y=10;z=30";

//     // cout << strtok(s1);

//     // string name = "   Oussama tailba Is The Goat of the dev   ";

//     // cout << "Size: " << name.size() << endl;
//     // cout << "Length: " << name.length() << endl;
//     // cout << "Capacity: " << name.capacity() << endl;
//     // cout << "Max_size: " << name.max_size() << endl;
//     // cout << name << endl;
//     // // name.clear();
//     // cout << name << endl;
//     // // cout << "Empty: " << name.empty() << endl;

//     // string s = "Hello";
//     // // s.append(" World");
//     // // s.insert(2, "World", 2);

//     // s.push_back(' ');
//     // s.append("World");

//     // // string poped =
//     // s.pop_back();

//     // cout << s << endl;

//     // for (char character : s)
//     // {
//     //     cout << character << endl;
//     // }

//     // string str = "Oussama kaoutar";
//     // // char dist[20];

//     // // cout << "Before copy: " << dist << endl;
//     // // str.copy(dist, str.length());
//     // // dist[str.length()] = '\0';
//     // // cout << "After copy: " << dist << endl;

//     // // cout << str.find("a234") << endl;
//     // // cout << str.find('a') << endl;
//     // // cout << str.find_first_of('a') << endl;
//     // // cout << str.find_first_of("as") << endl;
//     // // // cout << str.find_first_of('a', 5) << endl;
//     // // // cout << str.rfind('a') << endl;
//     // // // cout << str.find_last_of('a') << endl;
//     // // str.insert(8, "<3");
//     // // cout << str.substr(8, 4) << endl;

//     // // cout << str.back() << endl;
//     // // cout << str.front() << endl;

//     // string str1 = "Hello", str2 = " World!";

//     // str1 += str2;

//     // cout << str1 << endl;

//     string str = "Oussama kaoutar";

//     // string::iterator it;

//     // for (it = str.end(); it != str.begin(); it++)
//     // {
//     //     cout << *it << endl;
//     // }

//     // for (char chara : str)
//     // {
//     //     cout << chara << endl;
//     // }

//     string::reverse_iterator rit;

//     for (rit = str.rbegin(); rit != str.rend(); rit++)
//     {
//         cout << *rit << endl;
//     }

//     return 0;
// }

#include <iostream>
#include <string>

using namespace std;

int get_str_length(string str);
void to_lower_case(string *str);
bool is_palindrome(string str);
string get_username_from_email(string str);

int main()
{
    // string name = "OUSSAMA TAILBAZ";
    // char nintyOne = 91;

    // cout << "91: " << nintyOne << endl;

    // toLowerCase(&name);

    // cout << name << endl;
    // // int length = getStrLength(name);

    // // cout << "My Length is " << length << endl;
    // // cout << "Actual Length is " << name.length() << endl;

    // string name2 = "OussuO", reversed = "OussuO";
    // int comp = name2.compare(reversed);

    // cout << comp << endl;

    // string name = "Ous32suO";
    // bool checked = is_palindrome(name);
    // if (checked)
    //     cout << name << " is palendrome\n";
    // else
    //     cout << name << " is not palendrome\n";

    // string email = "KaoutarTaki0101@gmail.com";
    // string username = get_username_from_email(email);

    // cout << "your username from email is " << username << endl;

    string email = "KaoutarTaki0101@gmail.com";
    int _idx = (int)email.find('@');
    string username = email.substr(0, _idx);

    cout << "your username from email is " << username << endl;
}

int get_str_length(string str)
{
    int length = 0;
    char character = str[0];

    while (character != '\0')
    {
        length++;
        character = str[length];
    }

    return length;
}

void to_lower_case(string *str)
{
    for (char &character : *str)
    {
        if (character >= 65 && character <= 90)
            character = character + 32;
    }
}

bool is_palindrome(string str)
{
    string reversedStr = "";

    string::reverse_iterator rit;

    for (rit = str.rbegin(); rit != str.rend(); rit++)
    {
        reversedStr += *rit;
    }

    return !(bool)str.compare(reversedStr);
}

string get_username_from_email(string str)
{
    string username = "";

    string::iterator it;

    for (it = str.begin(); it != str.end(); it++)
    {
        if (*it == '@')
        {
            break;
        }

        username += *it;
    }

    return username;
}