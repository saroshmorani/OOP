#include<iostream>
#include<string>
using namespace std;

class Vehicle {
protected:
    int ID;
    static int totalDeliveries;

public:
    Vehicle(int id): ID(id) {
        totalDeliveries++;
    }

    virtual ~Vehicle() {
        totalDeliveries--;
    }

    virtual void calcDelRoute() {
        cout << "Calculating general delivery route..." << endl;
    }

    virtual void estDelTime() {
        cout << "Estimating general delivery time..." << endl;
    }

    virtual void command(string cmd, int packageID) {
        cout << "Vehicle " << ID << " is executing command: " << cmd 
             << " for Package Number" << packageID << endl;
    }

    virtual void command(string cmd, int packageID, string urgency) {
        cout << "Vehicle " << ID << " is executing command: " << cmd 
             << " for Package Number" << packageID << " with urgency: " << urgency << endl;
    }

    friend bool operator==(const Vehicle& v1, const Vehicle& v2);
    friend void resolveConflict(Vehicle& v1, Vehicle& v2);

    int getID() const {
        return ID;
    }
};

int Vehicle::totalDeliveries = 0;

bool operator==(const Vehicle& v1, const Vehicle& v2) {
    return v1.ID == v2.ID;
}

void resolveConflict(Vehicle& v1, Vehicle& v2) {
    if (v1.ID < v2.ID) {
        cout << "Vehicle " << v1.ID << " is more efficient.\n";
    } else {
        cout << "Vehicle " << v2.ID << " is more efficient.\n";
    }
}

class RamzanDrone : public Vehicle {
public:
    RamzanDrone(int id): Vehicle(id) {}

    void calcDelRoute() override {
        cout << "Drone is calculating aerial high-speed route...\n";
    }

    void command(string cmd, int packageID, string urgency) override {
        cout << "Drone is handling the urgent package #: " << packageID 
             << ". Turbo flight mode activated for Iftar!"<<endl;
    }
};

class RamzanTimeShip : public Vehicle {
public:
    RamzanTimeShip(int id): Vehicle(id) {}

    void calcDelRoute() override {
        cout << "TimeShip id verifying the timeline and setting the path...\n";
    }

    void command(string cmd, int packageID, string urgency) override {
        cout << "TimeShip is validating historical data for urgent package #: " 
             << packageID << "Timeline integrity is ensured.\n";
    }
};

class RamzanHyperPod : public Vehicle {
public:
    RamzanHyperPod(int id): Vehicle(id) {}

    void calcDelRoute() override {
        cout << "HyperPod is calculating underground tunnel route for bulk delivery...\n";
    }

    void command(string cmd, int packageID, string urgency) override {
        cout << "HyperPod is optimizing bulk delivery for package #: " << packageID 
             << " with urgency level: " << urgency << endl;
    }
};

int main() {
    RamzanDrone d1(101);
    RamzanTimeShip t1(102);
    RamzanHyperPod h1(103);

    d1.calcDelRoute();
    d1.command("Deliver", 7438, "urgent");

    t1.calcDelRoute();
    t1.command("Deliver", 1843, "urgent");

    h1.calcDelRoute();
    h1.command("Deliver", 5356, "normal");

    cout << "\nConflict Resolution:\n";
    resolveConflict(d1, t1);

    cout << "\nOperator Overloading:\n";
    if (d1 == h1) {
        cout << "Drone and HyperPod are equally efficient\n";
    } else {
        cout << "Drone and HyperPod differ in efficiency\n";
    }

    return 0;
}

