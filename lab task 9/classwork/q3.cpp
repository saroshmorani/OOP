#include <iostream>
#include <string>
using namespace std;

class PatientRecord {
private:
    string name, ID, dob;
    string medicalHistory, billingDetails;

public:
    PatientRecord(string n, string i, string d)
        : name(n), ID(i), dob(d), medicalHistory("None"), billingDetails("None") {}

    string getPublicData() const {
        return "Name: " + name + ", ID: " + ID;
    }

    string getMedicalData(string role) const {
        if (role == "Doctor") return medicalHistory;
        return "Access Denied";
    }

    void updateMedicalHistory(string history, string role) {
        if (role == "Doctor") medicalHistory = history;
    }

    void addBillingDetails(string bill, string role) {
        if (role == "Billing") billingDetails = bill;
    }

    string getBillingDetails(string role) const {
        if (role == "Billing") return billingDetails;
        return "Access Denied";
    }
};

int main() {
    PatientRecord p("Hassan", "P1001", "01-01-1990");

    p.updateMedicalHistory("Diagnosed with flu", "Doctor");
    p.addBillingDetails("Rs. 5000 for treatment", "Billing");

    cout << "Receptionist tries to get medical data: " << p.getMedicalData("Receptionist") << endl;
    cout << "Doctor sees medical history: " << p.getMedicalData("Doctor") << endl;
    cout << "Billing Staff sees billing: " << p.getBillingDetails("Billing") << endl;
}

