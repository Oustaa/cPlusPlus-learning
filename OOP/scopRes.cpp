#include <iostream>
#include <string>

using namespace std;

class User
{
private:
    string username;
    string password;

public:
    User(string username, string password)
    {
        this->username = username;
        this->password = password;
    }

    string get_username()
    {
        return username;
    }

    bool login(string, string);
};

bool User::login(string username, string password)
{
    if (username != this->username || password != this->password)
        return false;
    return true;
}

int main()
{
    User ousta("ousta6", "password");

    string password, username;

    cout << "Enter you username here: ";
    getline(cin, username);
    cout << "Enter you password here: ";
    getline(cin, password);

    bool connected = ousta.login(username, password);

    if (connected)
        cout << "Welcome " << ousta.get_username() << endl;
    else
        cout << "Failed to login." << endl;

    return 0;
}