#include <iostream>
using namespace std;

class Ghost {
public:
    string WorkerName;
    int scareLevel;
    Ghost(string w, int s) : WorkerName(w), scareLevel(s) {}
    virtual ~Ghost() {}

    virtual void perform() const = 0;
    int getScareLevel() const { return scareLevel; }
    string getWorkerName() const { return WorkerName; }

    friend ostream& operator<<(ostream& os, const Ghost& g) {
        os << "Ghost played by: " << g.WorkerName << ", Scare Level: " << g.scareLevel;
        return os;
    }
};


class Banshee : public Ghost {
public:
    Banshee(string w, int s) : Ghost(w, s) {}

    void perform() const override {
        cout << "Banshee screams loudly!" << endl;
    }

    Banshee operator+(const Ghost& other) const {
        return Banshee(WorkerName + " & " + other.WorkerName, scareLevel + other.scareLevel);
    }
};

class Poltergeist : virtual public Ghost {
public:
    Poltergeist(string w, int s) : Ghost(w, s) {}

    void perform() const override {
        cout << "Poltergeist moves objects!" << endl;
    }
};

class ShadowGhost : virtual public Ghost {
public:
    ShadowGhost(string w, int s) : Ghost(w, s) {}

    void perform() const override {
        cout << "ShadowGhost whispers creepily..." << endl;
    }
};

class ShadowPoltergeist : public ShadowGhost, public Poltergeist {
public:
    ShadowPoltergeist(string w, int s) : Ghost(w, s), ShadowGhost(w, s), Poltergeist(w, s) {}

    void perform() const override {
        ShadowGhost::perform();
        Poltergeist::perform();
    }
};

class Visitor {
public:
    string name;
    int bravery;

    Visitor() : name(""), bravery(0) {}
    Visitor(string n, int b) : name(n), bravery(b) {}

    void react(const Ghost& ghost) const {
        if (ghost.getScareLevel() < bravery - 3)
            cout << name << " laughs and taunts the ghost!" << endl;
        else if (ghost.getScareLevel() > bravery + 3)
            cout << name << " screams and runs away!" << endl;
        else
            cout << name << "'s voice shakes in fear." << endl;
    }
};

class HauntedHouse;

void visit(Visitor visitors[], int numVisitors, HauntedHouse& house);

class HauntedHouse {
public:
    string name;
    Ghost* ghosts[5];
    int ghostCount;

    HauntedHouse(string n) : name(n), ghostCount(0) {}

    ~HauntedHouse() {
        for (int i = 0; i < ghostCount; i++) {
            delete ghosts[i];
        }
    }

    void addGhost(Ghost* g) {
        if (ghostCount < 5) {
            ghosts[ghostCount++] = g;
        } else {
            cout << "Haunted house is full! Cannot add more ghosts." << endl;
        }
    }

    friend void visit(Visitor visitors[], int numVisitors, HauntedHouse& house);
};

void visit(Visitor visitors[], int numVisitors, HauntedHouse& house) {
    cout << "Visitors enter " << house.name << "..." << endl;

    for (int i = 0; i < numVisitors; i++) {
        cout << visitors[i].name << " is exploring..." << endl;

        for (int j = 0; j < house.ghostCount; j++) {
            house.ghosts[j]->perform();
            visitors[i].react(*house.ghosts[j]);
        }
    }
}

int main() {
    HauntedHouse hh1("Cursed Mansion");
    HauntedHouse hh2("Abyss Asylum");

    hh1.addGhost(new Banshee("Alyssa", 3));
    hh1.addGhost(new Poltergeist("Babar", 6));
    hh1.addGhost(new ShadowGhost("Chatur", 8));

    hh2.addGhost(new ShadowPoltergeist("Dawood", 5));

    Visitor visitors[3] = {
        Visitor("Jamshed", 2),
        Visitor("Eman", 6),
        Visitor("Laiba", 9)
    };

    visit(visitors, 3, hh1);
    visit(visitors, 3, hh2);

    return 0;
}
