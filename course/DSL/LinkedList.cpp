#include <iostream>
#include <map>

using namespace std;

struct User
{
    string name;
    int age;
};

void log_user(int id, User u)
{
    cout << id << ": " << u.name << " is " << u.age << " years old." << endl;
}

// template <class T>
// class LinkedList
// {
// public:
//     T value;
//     LinkedList *next;
//     LinkedList *head;

//     LinkedList(T value)
//     {
//         LinkedList<T> head;

//         head.value = value;
//         head.next = nullptr;

//         this->head = head;
//     }

//     void push(T value)
//     {

//         return;
//     }
// };

int main()
{
    // LinkedList<int> myLinkedList(34);

    // vector<int> myVector = {1, 2, 3, 4, 5, 6, 7};

    // myVector.push_back(27);

    // cout << myVector[1] << endl;

    // // cout << myVector.size() << endl;

    // vector<int>::iterator itr = myVector.begin();

    // while (itr != myVector.end())
    // {
    //     cout << *itr << endl;

    //     itr++;
    // }

    // for (itr; itr != myVector.end(); itr++)
    //     cout << *itr << endl;

    // for (int &a : myVector)
    // {
    //     a++;
    // }

    // for (int a : myVector)
    // {
    //     cout << a << endl;
    // }

    // set<string> mySet;

    // mySet.insert("Oussama");
    // mySet.insert("Oussama");
    // mySet.insert("Kaoutar");
    // mySet.insert("Kaoutar");
    // mySet.insert("Kaoutar");
    // mySet.insert("Kaoutar");
    // mySet.insert("123");
    // mySet.insert("12323");
    // mySet.insert("12323");

    // cout << mySet.max_size() << endl;
    // cout << mySet[1] <<  endl;

    // for (string value : mySet)
    //     cout << value << endl;

    map<int, User> users;

    users.insert(pair<int, User>(1, User{"Oussama Tailba", 27}));
    users.insert(pair<int, User>(2, User{"kaoutar Taki", 22}));

    map<int, User>::iterator users_itr = users.begin();

    while (users_itr != users.end())
    {

        log_user(users_itr->first, users_itr->second);

        users_itr++;
    }

    map<int, User>::iterator kt_itr = users.find(2);
    cout << "--------------------------------------" << endl;
    log_user(kt_itr->first, kt_itr->second);

    return 0;
}