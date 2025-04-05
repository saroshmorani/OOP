#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    int empID;

public:
    virtual void getData() {
        cout << "Enter Employee ID: ";
        cin >> empID;
    }

    virtual void displayData() const {
        cout << "Employee ID: " << empID << endl;
    }
};

class Admin : public Person {
private:
    string name;
    float monthlyIncome;

public:
    void getData() override {
        Person::getData();
        cout << "Enter Admin Name: ";
        cin.ignore(); // to clear newline from buffer
        getline(cin, name);
        cout << "Enter Monthly Income: ";
        cin >> monthlyIncome;
    }

    float bonus() const {
        return monthlyIncome * 12 * 0.05f;
    }

    void displayData() const override {
        Person::displayData();
        cout << "Name: " << name << endl;
        cout << "Monthly Income: $" << monthlyIncome << endl;
        cout << "Annual Bonus (5%): $" << bonus() << endl;
    }
};

class Accounts : public Person {
private:
    string name;
    float monthlyIncome;

public:
    void getData() override {
        Person::getData();
        cout << "Enter Accounts Employee Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Monthly Income: ";
        cin >> monthlyIncome;
    }

    float bonus() const {
        return monthlyIncome * 12 * 0.05f;
    }

    void displayData() const override {
        Person::displayData();
        cout << "Name: " << name << endl;
        cout << "Monthly Income: $" << monthlyIncome << endl;
        cout << "Annual Bonus (5%): $" << bonus() << endl;
    }
};
int main() {
    Admin adminEmp;
    Accounts accountsEmp;

    cout << "--- Enter Admin Details ---\n";
    adminEmp.getData();

    cout << "\n--- Enter Accounts Employee Details ---\n";
    accountsEmp.getData();

    cout << "\n--- Admin Employee Info ---\n";
    adminEmp.displayData();

    cout << "\n--- Accounts Employee Info ---\n";
    accountsEmp.displayData();

    return 0;
}

