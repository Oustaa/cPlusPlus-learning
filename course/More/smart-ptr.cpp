#include <iostream>
#include <memory>

using namespace std;

class Person
{
};

void fun()
{
    // Person *p_ptr = new Person();
    // unique_ptr<Person> ptr(new Person());
    // this is not alowed bc its unique_ptr
    // unique_ptr<Person> ptr2 = ptr;
    // you could do it as follow
    // unique_ptr<Person> ptr2 = move(ptr);

    weak_ptr<Person> ptr(new Person());
    weak_ptr<Person> ptr2 = ptr;
    weak_ptr<Person> ptr3 = ptr2;
    weak_ptr<Person> ptr4 = ptr3;

    // cout << ptr.use_count() << endl;

    // Same as Shared pointer except that they don't keep track of how many pointer are pointing to the object

    // delete p_ptr;
}

template <class T>
void fun_cb(T cb)
{
    cb();
}

int main()
{
    fun_cb([]
           { cout << "Oussama Is the best" << endl; });

    []
    { cout << "Oussama Is the best\n"; }();

    // flush();

    while (true)
    {
        fun();
    }
    return 0;
}