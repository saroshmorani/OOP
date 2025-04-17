#include <iostream>
using namespace std;

class Person {
public:
    virtual void getData() {
        cout << "Enter name: ";
        cin >> name;
    }

    virtual void displayData() {
        cout << "Name: " << name << endl;
    }

    virtual void bonus() = 0;

protected:
    string name;
};

class Admin : virtual public Person {
public:
    void getData() override {
        Person::getData();
        cout << "Enter admin salary: ";
        cin >> salary;
    }

    void displayData() override {
        Person::displayData();
        cout << "Admin Salary: $" << salary << endl;
    }

    void bonus() override {
        cout << "Admin Bonus: $" << salary * 0.10 << endl;
    }

protected:
    float salary;
};

class Account : virtual public Person {
public:
    void getData() override {
        Person::getData();
        cout << "Enter account balance: ";
        cin >> balance;
    }

    void displayData() override {
        Person::displayData();
        cout << "Account Balance: $" << balance << endl;
    }

    void bonus() override {
        cout << "Account Bonus: $" << balance * 0.05 << endl;
    }

protected:
    float balance;
};

class Master : public Admin, public Account {
public:
    void getData() override {
        Admin::getData();
        cout << "Enter account balance (from Master): ";
        cin >> balance;
    }

    void displayData() override {
        Admin::displayData();
        cout << "Account Balance: $" << balance << endl;
    }

    void bonus() override {
        float totalBonus = salary * 0.10 + balance * 0.05;
        cout << "Total Bonus (Master): $" << totalBonus << endl;
    }
};

int main() {
    Person* ptr;
    Master m;
    
    ptr = &m;
    ptr->getData();
    cout << "\nDisplaying Data:\n";
    ptr->displayData();
    cout << "\nCalculating Bonus:\n";
    ptr->bonus();

    return 0;
}

