#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string firstName;
    string lastName;
    double monthlySalary;

public:
    Employee(string fName, string lName, double salary) {
        firstName = fName;
        lastName = lName;
        monthlySalary = (salary > 0)? salary : 0.0;
    }

    void setFirstName(string fName) {
      firstName = fName;
    }
    string getFN() {
      return firstName;
    }

    void setLastName(string lName) {
      lastName = lName;
    }
    string getLN() {
      return lastName;
    }

    void setMonthlySalary(double salary) {
        monthlySalary = (salary > 0) ? salary : 0.0;
    }
    double getMonthlySalary() {
      return monthlySalary;
    }

    double getYearlySalary() {
      return monthlySalary * 12;
    }

    void raise(double percent) {
        monthlySalary += monthlySalary*(percent / 100);
    }
};

int main() {
    Employee e1("James", "Dan", 3000.0);
    Employee e2("Aren", "Sands", 4000.0);

    cout << "Initial Salaries per year:" << endl;
    cout << e1.getFN() << " " <<e1.getLN() << ": $" << e1.getYearlySalary() << endl;
    cout << e2.getFN() << " " << e2.getLN() << ": $" << e2.getYearlySalary() << endl;

    e1.raise(10);
    e2.raise(10);

    cout << "Yearly Salaries after the raise:" << endl;
    cout << e1.getFN() << " " << e1.getLN() << ": $" << e1.getYearlySalary() << endl;
    cout << e2.getFN() << " " << e2.getLN() << ": $" << e2.getYearlySalary() << endl;

    return 0;
}