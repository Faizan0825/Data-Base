#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string reg;
    string lname;
    string fname;
    string prog;
    float gpa;
    int num;

    int size = 0;
    cout << "enter number of students to enter: ";
    cin >> size;

    ofstream data("data.csv");
    if (!data)
    {
        cout << "error occured cant  open file..\n";
        return 1;
    }


    if (data.tellp() == 0)
    {
        data << "registration, first name,last name,program,number,cgpa" << endl;
    }


    for (int i = 0; i < size; i++)
    {
        cout << "Enter registration, first name, last name, program, number, and GPA: " << endl;
        cin >> reg >> fname >> lname >> prog >> num >> gpa;
        data << reg << "," << fname << "," << lname << "," << prog << "," << num << "," << gpa << endl;
    }

    char cont;
    cout << "Enter 1 to append more data or 0 to exit: ";
    cin >> cont;

    if (cont == 1)
    {

        ofstream data("data.csv", ios::app);
        if (!data) {
            cout << "cant open file..\n";
            return 1;
        }

        cout << "enter extra students to enter: ";
        cin >> size;


        for (int i = 0; i < size; i++) {

            cin >> reg >> fname >> lname >> prog >> num >> gpa;
            data << reg << "," << fname << "," << lname << "," << prog << "," << num << "," << gpa << endl;
        }
    }

    data.close();
    return 0;
}
