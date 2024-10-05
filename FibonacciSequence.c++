#include <iostream>

void iterativeApproach(int n);
int recursiveApproach(int n);

int main()
{
    int n;
    std::cout << "enter the n:";
    std::cin >> n;

    // iterativeApproach(n);
    for (int i = 0; i < n; ++i)
        std::cout << recursiveApproach(i) << " ";
}

void iterativeApproach(int n)
{
    long long int start = 0, next = 1, temp;

    for (int i = 0; i < n; i++)
    {
        temp = next;
        next = start + next;

        std::cout << start << " ";
        start = temp;
    }

    std::cout << std::endl;
}

int recursiveApproach(int n)
{
    if (n <= 1)
        return n;
    return recursiveApproach(n - 1) + recursiveApproach(n - 2);
}
