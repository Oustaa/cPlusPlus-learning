#include <iostream>
#include <cmath>

int main(int argc, char **argv, char **envp)
{
    double r = std::sqrt(49);
    std::cout << r << std::endl;

    for (char **param = envp; *param != nullptr; ++param)
    {
        std::cout << "-----------------------------------------------------------" << std::endl;
        std::cout << *param << std::endl;
    }

    return 0;
}
