#include <iostream>
using namespace std;

class Car {
private:
    string engine;
    int horsepower;
    int seating_capacity;
    int no_of_speakers;

public:
   
    Car(string eng, int hp, int seat, int speakers)
        : engine(eng), horsepower(hp), seating_capacity(seat), no_of_speakers(speakers) {}
    
    void display() const {
        cout << "Engine: " << engine << "\n";
        cout << "Horsepower: " << horsepower << "\n";
        cout << "Seating Capacity: " << seating_capacity << "\n";
        cout << "No of Speakers: " << no_of_speakers << "\n";
    }

    void updateSpeakers(int new_speakers) {
        no_of_speakers = new_speakers;
    }
};

int main() {
    Car rivo("V8", 400, 5, 6);
    cout << "Before update:\n";
    rivo.display();
    
    rivo.updateSpeakers(8); 
    
    cout << "\nAfter update:\n";
    rivo.display();
    
    return 0;
}
