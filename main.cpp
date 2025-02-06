// #include <stdio.h>
#include <iostream>

#define SQRT(arg) ((arg) * (arg))

using namespace std;

constexpr int double_it(int arg) { return arg * arg; }

string mergeAlternately(string word1, string word2)
{
    string merged, left_over = "";
    int min_len, word1_len = word1.length(), word2_len = word2.length();

    if (word1_len != word2_len)
    {
        min_len = min(word1.length(), word2.length());
        left_over = word1_len > word2_len ? word1.substr(min_len, word1_len) : word2.substr(min_len, word2_len);
    }
    else
    {
        min_len = word1_len;
    }

    for (int i = 0; i < min_len; i++)
    {
        merged += word1[i];
        merged += word2[i];
    }

    merged += left_over;

    return merged;
}

int main()
{

    string mergerd = mergeAlternately("Oussama", "1234");
    cout << mergerd << endl;

    return 0;

    // cout << SQRT(4) << endl;
    // cout << SQRT(4 + 1) << endl;

    // int bad_result = double_it(4 + 1);

    // cout << bad_result << endl;
    // return 0;
    string name = "Oussama Tail";
    int length = name.length();
    cout << min(length, 15) << endl;
}