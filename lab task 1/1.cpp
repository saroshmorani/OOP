#include <iostream>
#include <cmath> 
#include <cstdlib> 

using namespace std;

float findSecondHighest(float *num, int size) {
    if (size < 2) {
        cout << "Array should have more than two elements." << endl;
        return 0;
    }

    float max = -INFINITY;  
    float secondMax = -INFINITY;

    for (int i = 0; i < size; i++) {
        if (*(num + i) > max) {
            secondMax = max;
            max = *(num + i);
        } else if (*(num + i) > secondMax && *(num + i) < max) {
            secondMax = *(num + i);
        }
    }

    return (secondMax == -INFINITY) ? 0 : secondMax;
}

int main(int argc, char *argv[]) {
    const int size = 20;
    float num[size];

    if (argc != size + 1) {
        cout << "Please provide exactly 20 float numbers as command-line arguments." << endl;
        return 1;
    }

    for (int i = 0; i < size; i++) {
        num[i] = atof(argv[i + 1]); 
    }

    float secondMax = findSecondHighest(num, size);

    if (secondMax != 0) {
        cout << "The second highest number is: " << secondMax << endl;
    } else {
        cout << "Couldn't determine the second highest number." << endl;
    }

    return 0;
}

