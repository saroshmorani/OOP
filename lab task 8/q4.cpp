#include <iostream>
using namespace std;

class Person {
protected:
    string name, id, phoneNumber, email;

public:
    Person(string n, string i, string phone, string mail)
        : name(n), id(i), phoneNumber(phone), email(mail) {}

    virtual void displayInfo() {
        cout << "Name: " << name << "\nID: " << id << "\nPhone: " << phoneNumber << "\nEmail: " << email << "\n";
    }

    virtual void updateInfo(string newEmail) {
        email = newEmail;
    }
};

class Student : public Person {
    string course1, course2, GPA;
    int enrollmentYear;

public:
    Student(string n, string i, string phone, string mail, int year, string c1, string c2, string gpa)
        : Person(n, i, phone, mail), enrollmentYear(year), course1(c1), course2(c2), GPA(gpa) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Enrollment Year: " << enrollmentYear << "\nGPA: " << GPA
             << "\nCourses Enrolled: " << course1 << ", " << course2 << "\n";
    }
};

class Professor : public Person {
    string course1, course2;
    double salary;

public:
    Professor(string n, string i, string phone, string mail, double sal, string c1, string c2)
        : Person(n, i, phone, mail), salary(sal), course1(c1), course2(c2) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Salary: $" << salary << "\nCourses Taught: " << course1 << ", " << course2 << "\n";
    }
};

class Staff : public Person {
    string position;
    double salary;

public:
    Staff(string n, string i, string phone, string mail, string pos, double sal)
        : Person(n, i, phone, mail), position(pos), salary(sal) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Position: " << position << "\nSalary: $" << salary << "\n";
    }
};

int main() {
    Student s1("Ali Khan", "S953", "0331-123167", "ali@nu.edu.pk", 2023, "OOP", "DLD", "3.9");
    Professor p1("Dr. Ahmed", "P856", "0900-6538210", "ahmed@nu.edu.pk", 200000, "OOP", "Data Structures");
    Staff st1("Mr. Rehman", "ST729", "0782-9873243", "rehman@nu.edu.pk", "Admin", 150000);

    cout << "\nUniversity Management System:\n";
    s1.displayInfo();
    cout << "\n";
    p1.displayInfo();
    cout << "\n";
    st1.displayInfo();

    return 0;
}

