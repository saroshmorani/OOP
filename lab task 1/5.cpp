#include <iostream>
#include <cstdlib> 
#include <iomanip> 
using namespace std;

void calculateAmounts(double* adultPrice, double* childPrice, int* adultSold, int* childSold, double* donationPercent, double* gross, double* donated, double* net) {
    *gross = (*adultPrice * *adultSold) + (*childPrice * *childSold);
    *donated = (*gross * (*donationPercent / 100));
    *net = *gross - *donated;
}

void displayResults(char* movie, int* totalTickets, double* gross, double* donationPercent, double* donated, double* net) {
    cout << "\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
    cout << left << setw(40) << "Movie Name:" << right << movie << endl;
    cout << left << setw(40) << "Number of Tickets Sold:" << right << *totalTickets << endl;
    cout << left << setw(40) << "Gross Amount:" << right << "$ " << fixed << setprecision(2) << *gross << endl;
    cout << left << setw(40) << "Percentage of Gross Amount Donated:" << right << fixed << setprecision(2) << *donationPercent << "%" << endl;
    cout << left << setw(40) << "Amount Donated:" << right << "$ " << fixed << setprecision(2) << *donated << endl;
    cout << left << setw(40) << "Net Sale:" << right << "$ " << fixed << setprecision(2) << *net << endl;
    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n";
}

int main(int argc, char* argv[]) {
    char* movieName = argv[1];
    double adultPrice = atof(argv[2]);
    double childPrice = atof(argv[3]);
    int adultSold = atoi(argv[4]);
    int childSold = atoi(argv[5]);
    double donationPercent = atof(argv[6]);

    int totalTickets = adultSold + childSold;
    double gross, donated, net;

    calculateAmounts(&adultPrice, &childPrice, &adultSold, &childSold, &donationPercent, &gross, &donated, &net);
    displayResults(movieName, &totalTickets, &gross, &donationPercent, &donated, &net);

    return 0;
}
