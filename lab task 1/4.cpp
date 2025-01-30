#include <iostream>
#include <cstdlib>
using namespace std;

void convert(double kg, double &pounds) {
    const double conversionFactor = 2.2;
    pounds = kg * conversionFactor;
}

void display(double kg, double pounds) {
    kg = (int)(kg * 100 + 0.5) / 100.0;
    pounds = (int)(pounds * 100 + 0.5) / 100.0;

    cout << "Weight in Kilograms: " << kg << " kg" << endl;
    cout << "Weight in Pounds: " << pounds << " lbs" << endl;
}

int main(int argc, char* argv[]) {
    if (argc != 2) { 
        cout << "Usage: <program> <Weight in Kilograms>" << endl;
        return 1;
    }

    double kg = atof(argv[1]);
    if (kg <= 0) { 
        cout << "Error: Please enter a valid positive weight in kilograms." << endl;
        return 1;
    }

    double pounds = 0.0;
    convert(kg, pounds);
    
    display(kg, pounds);

    return 0;
}
