#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct student
{
    string name;
    string roll_no;
    string div;
};

void AddStudent()
{
    student obj;
    fstream file;
    file.open("Student_Database.txt", ios::app);
    cout<<"Enter the roll No: ";
    cin>>obj.roll_no;

    cin.ignore();

    cout<<"Enter the name: ";
    getline(cin, obj.name);

    cout<<"Enter the division: ";
    cin>>obj.div;

    file<<obj.roll_no<<", "<<obj.name<<", "<<obj.div<<endl;
    cout<<"Data has successfully written"<<endl;
}

void DeleteStudent()
{
    ifstream Rfile("Student_Database.txt");
    ofstream Wfile("temp.txt", ios::app);

    string Roll;
    cout<<"Enter the roll Number: ";
    cin>>Roll;

    bool found = false;

    string line;
    while(getline(Rfile, line))
    {
        if(line.find(Roll) != 0)
        {
            Wfile<<line<<endl;
        }
        else
        {
            found = true;
        }
    }

    Rfile.close();
    Wfile.close();

    remove("Student_Database.txt");
    rename("temp.txt", "Student_Database.txt");

    if(found)
    {
        cout<<"Record Successfully Deleted"<<endl;
    }
    else
    {
        cout<<"Record not Found"<<endl;
    }
}

void Search()
{
    cout<<"Enter the roll number that you want to search: ";
    string roll;
    cin>>roll;

    string line;
    ifstream file("student_database.txt");
    while(getline(file, line))
    {
        if(line.find(roll) == 0)
        {
            cout<<line<<endl;
            return;
        }
    }

    cout<<"Data not found!"<<endl;
}

int main()
{
    AddStudent();
    AddStudent();
    AddStudent();
    // DeleteStudent();
    Search();
    return 0;
}