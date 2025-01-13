#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    // write to a file
    // ofstream outfile("text.txt", ios::app);

    // outfile << "Hello My File, i am Oussama Tailba" << endl;

    // outfile.close();

    // ofstream my_file_out;
    // my_file_out.open("MyFile2.txt", ios::app);

    // my_file_out << "I Love Mom two";

    // read from a file
    string file_content;
    ifstream in_file;
    in_file.open("text.txt", ios::binary);

    // check if file existed by the following file_name or by using build in method file_name.is_open()
    if (!in_file.is_open())
        cout << "File text.txt can't be opened" << endl;
    else
        do
        {
            // in_file >> file_content;
            getline(in_file, file_content);
            cout << file_content << endl;
        } while (!in_file.eof());

    in_file.close();

    cout << std::setw(10) << "Hello" << endl;

    return 0;
}