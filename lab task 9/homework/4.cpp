#include <iostream>
using namespace std;

class Student {
public:
    virtual double getTuition(string status, int creditHours) = 0;

    virtual ~Student() {}
};

class GraduateStudent : public Student {
public:
    GraduateStudent() : researchTopic("") {}

    void setResearchTopic(string topic) {
        researchTopic = topic;
    }

    string getResearchTopic() const {
        return researchTopic;
    }

    double getTuition(string status, int creditHours) override {
        if (status == "undergraduate") return creditHours * 200;
        else if (status == "graduate") return creditHours * 300;
        else if (status == "doctoral") return creditHours * 400;
        else {
            cout << "Invalid status!" << endl;
            return 0;
        }
    }

private:
    string researchTopic;
};

int main() {
    GraduateStudent gs;

    string topic, status;
    int credits;

    cout << "Enter research topic: ";
    cin >> topic;
    gs.setResearchTopic(topic);

    cout << "Enter student status (undergraduate/graduate/doctoral): ";
    cin >> status;

    cout << "Enter number of credit hours: ";
    cin >> credits;

    double tuition = gs.getTuition(status, credits);

    cout << "\nResearch Topic: " << gs.getResearchTopic() << endl;
    cout << "Tuition Fee: $" << tuition << endl;

    return 0;
}

