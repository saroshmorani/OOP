#include <iostream>
#include <string>
using namespace std;

class TransportCard {
private:
    static int nextCardID;
    int cardID;
    bool isActive;
public:
    TransportCard() : cardID(nextCardID++), isActive(false) {}
    void activate() { isActive = true; }
    void deactivate() { isActive = false; }
    bool getStatus() const { return isActive; }
    int getCardID() const { return cardID; }
};
int TransportCard::nextCardID = 1;

class User {
protected:
    string name;
    int ID;
    TransportCard card;
public:
    User(string name, int ID) : name(name), ID(ID) {}
    virtual void payFees() = 0;
    virtual void displayInfo() const {
        cout << "Name: " << name << ", ID: " << ID << endl;
    }
};

class Student : public User {
public:
    Student(string name, int ID) : User(name, ID) {}
    void payFees() override {
        cout << "Student " << name << " paid semester fees." << endl;
        card.activate();
    }
};

class Teacher : public User {
public:
    Teacher(string name, int ID) : User(name, ID) {}
    void payFees() override {
        cout << "Teacher " << name << " paid monthly fees." << endl;
        card.activate();
    }
};

class Staff : public User {
public:
    Staff(string name, int ID) : User(name, ID) {}
    void payFees() override {
        cout << "Staff " << name << " paid monthly fees." << endl;
        card.activate();
    }
};

class Stop {
public:
    string name;
    Stop() : name("Undefined") {}
    Stop(string n) : name(n) {}
};

class Route {
private:
    Stop stops[10];
    int stopCount;
public:
    Route() : stopCount(0) {}
    void addStop(const Stop& stop) {
        if (stopCount < 10) {
            stops[stopCount] = stop;
            stopCount++;
        }
    }
    bool operator==(const Route& other) const {
        if (stopCount != other.stopCount) return false;
        for (int i = 0; i < stopCount; i++) {
            if (stops[i].name != other.stops[i].name) return false;
        }
        return true;
    }
};

int main() {
    Student s("Asim", 191);
    Teacher t("Dr. Akhtar", 754);
    Staff staff("Ms. Saima", 956);
    
    s.payFees();
    t.payFees();
    staff.payFees();
    
    Route r1, r2;
    r1.addStop(Stop("A"));
    r2.addStop(Stop("B"));
    
    if (r1 == r2) {
        cout << "Routes are the same." << endl;
    } else {
        cout << "Routes are different." << endl;
    }
    
    return 0;
}

