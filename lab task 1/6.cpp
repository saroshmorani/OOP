#include <iostream>
#include <iomanip> 
#include <cstdlib> 
#include <sstream> 

using namespace std;

int main(int argc, char* argv[]) {

    stringstream studentName;
    for (int i = 1; i < argc - 5; i++) {
        studentName << argv[i] << " ";
    }

    double scores[5];
    for (int i = 0; i < 5; i++) {
        scores[i] = atof(argv[i + argc - 5]); 
    }

    double total = 0;
    for (int i = 0; i < 5; i++) {
        total += scores[i];
    }
    double average = total / 5;

    cout << "Student name: " << studentName.str() << endl;
    cout << "Test scores: ";
    for (int i = 0; i < 5; i++) {
        cout << fixed << setprecision(2) << scores[i] << " "; 
    }
    cout << endl;
    cout << "Average test score: " << fixed << setprecision(2) << average << endl;

    return 0;
}