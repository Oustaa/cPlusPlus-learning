#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

struct is_palendrom_responce
{
    bool is_palendrom;
    string palendrom_part;
};

is_palendrom_responce is_palendrom(string str)
{
    int str_len = str.length();
    bool is_even = str_len % 2 == 0;
    int middle = str_len / 2;

    string left_side = str.substr(0, middle);
    string right_side = str.substr(is_even ? middle : middle + 1);

    reverse(right_side.begin(), right_side.end());

    bool is_palendrom = !(bool)left_side.compare(right_side);

    return is_palendrom_responce{is_palendrom, left_side};
}

int main()
{

    string str = "OussamaamassuO";
    // int middle = str.length() / 2;
    // reverse(str.begin(), str.end());

    // cout << middle << endl;

    // cout << str << endl;

    // cout << str.length() << endl;
    // cout << str.substr(0, middle) << endl;
    // cout << str.substr(middle) << endl;

    // cout << !(bool)str.compare("OussamaaamassuO") << endl;

    is_palendrom_responce is_str_palendrom = is_palendrom(str);

    if (is_str_palendrom.is_palendrom)
        cout
            << str << " is indeed palendrom, with its part " << is_str_palendrom.palendrom_part << endl;
    else
        cout << str << " is not palendrom." << endl;

    return 0;
}