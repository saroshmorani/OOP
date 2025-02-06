#include<iostream>
using namespace std;

struct Employee{
    int employee_id;
    char name[50];
    int salary;
};

struct Organization{
    char organisation_name[50];
    char organisation_number[20];
    struct Employee emp;
};

int main(){

    struct Organization org;

    cin.getline(org.organisation_name, 50);
    cin>>org.organisation_number;
    cin.ignore(); 
    cin>>org.emp.employee_id;
    cin.ignore();
    cin.getline(org.emp.name, 50);
    cin>>org.emp.salary;

    
    cout<<"Organisation Name: "<<org.organisation_name<<endl;
    cout<<"Organisation Number: "<<org.organisation_number<<endl;

    cout<<"Employee ID: "<<org.emp.employee_id<<endl;
    cout<<"Employee Name: "<<org.emp.name<<endl;
    cout<<"Employee Salary: "<<org.emp.salary<<endl;

    return 0;
}