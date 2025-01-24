#include <iostream>

int main(int argc, char *argv[], char *envp[])
{

    std::cout << "The number of passed arguments is: " << argc << std::endl;
    std::cout << "Arguments are: " << std::endl;

    for (int ix = 0; ix < argc; ++ix)
    {
        std::cout << argv[ix] << std::endl;
    }

    std::cout << "env: " << std::endl;

    for (const auto *env : envp)
    {
        std::cout << env << std::endl;
    }

    return 0;
}