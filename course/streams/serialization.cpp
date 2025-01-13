#include <iostream>
#include <fstream>

using namespace std;

class Student
{
public:
    string name;
    int rool;
    string branch;

    friend ostream &operator<<(ostream &o, Student &s);
    friend ofstream &operator<<(ofstream &ofs, Student &s);
    friend ifstream &operator>>(ifstream &ifs, Student &s);
};

ostream &operator<<(ostream &o, Student &s)
{
    cout << s.name << endl;
    cout << s.branch << endl;
    cout << s.rool << endl;

    return o;
}

ofstream &operator<<(ofstream &ofs, Student &s)
{
    ofs << s.name << endl;
    ofs << s.branch << endl;
    ofs << s.rool << endl;

    return ofs;
}

ifstream &operator>>(ifstream &ifs, Student &s)
{
    getline(ifs, s.name);
    getline(ifs, s.branch);
    ifs >> s.rool; // Read the integer field
    ifs.ignore();  // Ignore the newline character left by reading the integer

    // ifs >> s.name >> s.branch >> s.rool;

    return ifs;
}

int main()
{
    // ofstream ostudent_file;
    // Student s1;

    // s1.name = "Oussama Tailba";
    // s1.rool = 2;
    // s1.branch = "CS";

    // ostudent_file.open("student.txt", ios::trunc);

    // ostudent_file << s1;

    // ostudent_file.close();

    Student s1;
    ifstream istudent_file;
    istudent_file.open("student.txt");

    if (!istudent_file.is_open())
    {
        cout << "student.txt can't be opened" << endl;
        return 1;
    }

    istudent_file >> s1;

    cout << s1;

    istudent_file.close();

    return 0;
}