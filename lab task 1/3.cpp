#include <iostream>
#include <cstdlib>
using namespace std;

void calculateCharge(int units, float &charge, float &rate) {
    if (units <= 199) {
        rate = 16.20;
        charge = units * rate;
    }
    else if (units >= 200 && units < 300) {
        rate = 20.10;
        charge = units * rate;
    }
    else if (units >= 300 && units < 500) {
        rate = 27.10;
        charge = units * rate;
    }
    else {
        rate = 35.90;
        charge = units * rate;
    }
}

void applySurcharge(float &charge) {
    if (charge > 18000) {
        charge += charge * 0.15;
    }
}

void printBill(string customerID, string customerName, int units, float charge, float surcharge, float rate) {
    cout << "Customer ID : " << customerID << endl;
    cout << "Customer Name: " << customerName << endl;
    cout << "Units Consumed : " << units << endl;
    cout << "Amount Charges @Rs. " << rate << " per unit: " << (charge - surcharge) << endl;
    cout << "Surcharge Amount: " << surcharge << endl;
    cout << "Net Amount Paid by the Customer: " << charge << endl;
}

int main(int argc, char* argv[]) {

    string customerID = argv[1];
    string customerName = argv[2];
    int units = atoi(argv[3]);

    float charge = 0.0, rate = 0.0;
    calculateCharge(units, charge, rate);
    
    float surcharge = (charge > 18000) ? charge * 0.15 : 0.0;
    applySurcharge(charge);
    
    printBill(customerID, customerName, units, charge, surcharge, rate);
    
    return 0;
}