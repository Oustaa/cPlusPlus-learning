#include <iostream>
#include <string>
#include <stdexcept>

int string_to_int(const std::string &str)
{
    try
    {
        // std::stoi converts the string to an integer
        int num = std::stoi(str);
        return num;
    }
    catch (const std::invalid_argument &e)
    {
        // This exception is thrown if the input cannot be converted to an integer
        std::cerr << "Invalid input: '" << str << "' cannot be converted to an integer.\n";
    }
    catch (const std::out_of_range &e)
    {
        // This exception is thrown if the input is out of the range of integers
        std::cerr << "Out of range error: '" << str << "' is out of the range for an integer.\n";
    }

    return -1; // Return -1 in case of an error
}

int main()
{
    std::string input;
    std::cout << "Enter a number: ";
    std::cin >> input;

    int result = string_to_int(input) + 345;

    if (result != -1)
    {
        std::cout << "Converted number: " << result << std::endl;
    }
    else
    {
        std::cout << "Conversion failed." << std::endl;
    }

    return 0;
}
