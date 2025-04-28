#include<iostream>
#include<vector>
#include<limits>
#include<string>
#include<fstream>
#include<algorithm>

using namespace std;

class Employee
{
    public:
    string name, id, designation;
    float salary;
};

vector<Employee> employees;

void SaveEmployee()
{
    ofstream file("Student_Database.txt",ios::app);
    for(auto i : employees)
    {
        file<<i.id<<") "<<i.name<<"\t"<<i.designation<<"\t"<<i.salary<<endl;
    }
    file.close();
}

void AddEmployee()
{
    Employee e;

    cout<<"Enter the name: ";
    getline(cin, e.name);
    
    cout<<"Enter the ID: ";
    getline(cin, e.id);
    
    cout<<"Enter the designation: ";
    getline(cin, e.designation);
    
    cout<<"Enter the Salary: ";
    cin>>e.salary;
    
    cin.ignore();
    employees.push_back(e);
}

void RemoveEmployee()
{
    string id;
    cout<<"Enter the ID that you want to Delete: ";
    cin>>id;

    auto it = find_if(employees.begin(), employees.end(), [&](Employee a) {return a.id == id;});
    if(it!=employees.end())
    {
        employees.erase(it, employees.end());
        cout<<"Record deleted"<<endl;
    }
    else
    {
        cout<<"Record not Found!!"<<endl;
    }
}

void SearchEmployee()
{
    string id;
    cout<<"Enter the ID that you want to Search: ";
    cin>>id;

    auto it = find_if(employees.begin(), employees.end(), [&](Employee a) {return a.id == id;});
    if(it!=employees.end())
    {
        cout<<(*it).id<<") "<<(*it).name<<"\t"<<(*it).salary<<"\t"<<(*it).designation<<endl;
    }
    else
    {
        cout<<"Record not Found!!"<<endl;
    }
}

int main()
{
    AddEmployee();
    AddEmployee();
    AddEmployee();
    RemoveEmployee();
    SaveEmployee();
    SearchEmployee();
    return 0;
}