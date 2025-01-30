#include <iostream>
#include <cstdlib>

using namespace std;

void takeInput(float *num, int size) {
    cout << "Enter " << size << " elements:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> num[i];
    }
}

float add(float *num, int size) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += *(num + i);
    }
    return sum;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <size> <values...>" << endl;
        return 1;
    }

    int size = atoi(argv[1]);
    if (size <= 0) {
        cout << "Invalid size!" << endl;
        return 1;
    }

    float *num = new float[size];

    if (argc == size + 2) {
        
        for (int i = 0; i < size; i++) {
            num[i] = atof(argv[i + 2]); 
        }
    } else {
       
        takeInput(num, size);
    }

    float sum = add(num, size);

    cout << "The sum of the array is: " << sum << endl;

    delete[] num;
    return 0;
}
