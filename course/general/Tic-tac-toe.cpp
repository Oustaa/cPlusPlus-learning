#include <iostream>

void DrawMap();

int main(int argc, char **argv)
{
    DrawMap();

    return 0;
}

void DrawMap()
{
    system("clear");

    std::cout << "-------------" << std::endl;
    for (int i = 1; i <= 9; i++)
    {
        std::cout << "| " << i << " ";

        if (i % 3 == 0)
        {
            std::cout << "|" << std::endl;
            std::cout << "-------------" << std::endl;
        }
    }
}