#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Passenger;

class Flight {
private:
    string flightNumber, departure, arrival;
    int capacity, bookedSeats;

public:
    Flight(string num, string dep, string arr, int cap)
        : flightNumber(num), departure(dep), arrival(arr), capacity(cap), bookedSeats(0) {}

    bool bookSeat(Passenger& p);
    bool cancelSeat(Passenger& p);
    bool upgradeSeat(Passenger& p);
    int getAvailableSeats() const {
        return capacity - bookedSeats;
    }
};

class Passenger {
private:
    string ID, name;
    bool hasBooking;

public:
    Passenger(string i, string n) : ID(i), name(n), hasBooking(false) {}

    bool requestBooking(Flight& f) {
        if (!hasBooking && f.bookSeat(*this)) {
            hasBooking = true;
            return true;
        }
        return false;
    }

    bool requestCancel(Flight& f) {
        if (hasBooking && f.cancelSeat(*this)) {
            hasBooking = false;
            return true;
        }
        return false;
    }

    bool requestUpgrade(Flight& f) {
        if (hasBooking)
            return f.upgradeSeat(*this);
        return false;
    }

    friend class Flight;
};

bool Flight::bookSeat(Passenger& p) {
    if (bookedSeats < capacity) {
        bookedSeats++;
        return true;
    }
    return false;
}

bool Flight::cancelSeat(Passenger& p) {
    if (bookedSeats > 0) {
        bookedSeats--;
        return true;
    }
    return false;
}

bool Flight::upgradeSeat(Passenger& p) {
    cout << "Seat upgraded for " << p.name << endl;
    return true;
}

int main() {
    Flight f1("PK101", "Lahore", "Karachi", 2);
    Passenger p1("P001", "Zain");
    Passenger p2("P002", "Amna");

    cout << "Zain booking: " << (p1.requestBooking(f1) ? "Success" : "Failed") << endl;
    cout << "Amna booking: " << (p2.requestBooking(f1) ? "Success" : "Failed") << endl;

    Passenger p3("P003", "Usman");
    cout << "Usman booking: " << (p3.requestBooking(f1) ? "Success" : "Failed") << endl;

    p1.requestUpgrade(f1);
}

