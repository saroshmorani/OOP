#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

struct Employee {
    int id;
    string name;
    string designation;
    int years_of_service;
};

void writeDummyDataToFile(const string &filename) {
    ofstream file(filename);
    file << "1,John Doe,Manager,5\n";
    file << "2,Jane Smith,Developer,3\n";
    file << "3,Michael Brown,Manager,1\n";
    file << "4,Emily Davis,Developer,6\n";
    file << "5,James Wilson,Manager,2\n";
    file.close();
}

vector<Employee> readDataFromFile(const string &filename) {
    ifstream file(filename);
    vector<Employee> employees;
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        Employee emp;
        string temp;
        getline(ss, temp, ',');
        emp.id = stoi(temp);
        getline(ss, emp.name, ',');
        getline(ss, emp.designation, ',');
        getline(ss, temp, ',');
        emp.years_of_service = stoi(temp);
        employees.push_back(emp);
    }
    file.close();
    return employees;
}

void writeDataToFile(const string &filename, const vector<Employee> &employees) {
    ofstream file(filename);
    for (const auto &emp : employees) {
        file << emp.id << "," << emp.name << "," << emp.designation << "," << emp.years_of_service << "\n";
    }
    file.close();
}

vector<Employee> findManagerWithMinTwoYears(const vector<Employee> &employees) {
    vector<Employee> result;
    for (const auto &emp : employees) {
        if (emp.designation == "Manager" && emp.years_of_service >= 2) {
            result.push_back(emp);
        }
    }
    return result;
}

vector<Employee> deleteNonManagerWithMinTwoYears(const vector<Employee> &employees) {
    vector<Employee> result;
    for (const auto &emp : employees) {
        if (emp.designation == "Manager" && emp.years_of_service >= 2) {
            result.push_back(emp);
        }
    }
    return result;
}

vector<Employee> incrementIdAndYears(const vector<Employee> &employees) {
    vector<Employee> result;
    for (const auto &emp : employees) {
        Employee new_emp = emp;
        new_emp.id += 1;
        new_emp.years_of_service += 1;
        result.push_back(new_emp);
    }
    return result;
}

int main() {
    string filename = "employee_data.txt";

    writeDummyDataToFile(filename);

    vector<Employee> employees = readDataFromFile(filename);

    vector<Employee> managerWithMinTwoYears = findManagerWithMinTwoYears(employees);
    cout << "Query 1 - Manager with at least 2 years of service:\n";
    for (const auto &emp : managerWithMinTwoYears) {
        cout << emp.id << ", " << emp.name << ", " << emp.designation << ", " << emp.years_of_service << "\n";
    }

    vector<Employee> dataToWrite = deleteNonManagerWithMinTwoYears(employees);
    cout << "\nQuery 2 - Data after deleting non-manager with less than 2 years:\n";
    for (const auto &emp : dataToWrite) {
        cout << emp.id << ", " << emp.name << ", " << emp.designation << ", " << emp.years_of_service << "\n";
    }

    vector<Employee> incrementedData = incrementIdAndYears(managerWithMinTwoYears);
    cout << "\nQuery 3 - Incremented IDs and Years of service:\n";
    for (const auto &emp : incrementedData) {
        cout << emp.id << ", " << emp.name << ", " << emp.designation << ", " << emp.years_of_service << "\n";
    }

    writeDataToFile(filename, incrementedData);

    return 0;
}

