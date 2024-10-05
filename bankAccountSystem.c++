#include <iostream>

int printMenu();

class Account
{
private:
    int deposit = 0;
    std::string password = "123456789";
    std::string name = "";

public:
    Account(int deposit, std::string name)
    {
        this->name = name;
        this->deposit = deposit;
    }

public:
    int getDeposit()
    {
        return this->deposit;
    }

    void putDeposit(int newDeposit)
    {
        this->deposit += newDeposit;
    }

    void withdraw(int budget)
    {
        if (budget > this->deposit)
        {
            std::cout << "Your can't withdraw more than what you have\n";
        }
        else
        {
            this->deposit -= budget;
        }
    }

    bool checkCredentials(std::string name, std::string password)
    {
        return this->name == name && this->password == password;
    }
};

int main()
{
    Account account(1000, "Oussama Tailba");
    std::string name, password;

    std::cout << "enter you name in the cart: ";
    std::getline(std::cin, name);
    std::cout << "enter you password: ";
    std::cin >> password;

    if (!account.checkCredentials(name, password))
    {
        std::cout << "Your credentials are unvalid\n";
        return 1;
    }
    int deposit;

    while (true)
    {
        int action = printMenu();

        switch (action)
        {
        case 1:
            std::cout << "Your account balence is " << account.getDeposit() << std::endl;
            break;

        case 2:
            std::cout << "enter how much you want to withdraw: ";
            std::cin >> deposit;
            account.withdraw(deposit);
            break;

        case 3:
            std::cout << "enter how much you want to add: ";
            std::cin >> deposit;
            account.putDeposit(deposit);
            break;
        case 0:
            std::cout << "Logging out...\n";
            return 0;

        default:
            break;
        }
    }

    std::cout << account.getDeposit();
    return 0;
}

int printMenu()
{
    int action;

    do
    {
        std::cout << "Welcome to simple account system\n";
        std::cout << "0: for logging out\n";
        std::cout << "1: for checking your deposit\n";
        std::cout << "2: for withdraw a deposit\n";
        std::cout << "3: for putting a deposit\n";
        std::cout << "Your Action >> ";

        std::cin >> action;

        if (action == 1 || action == 2 || action == 3)
        {
            break;
        }
        std::cout << "The action you chose is unvalid\n";
    } while (true);

    return action;
}