#include <iostream>
#include <string>
using namespace std;

unsigned long generateHash(const string& password) {
    unsigned long hash = 5381;
    for (int i = 0; i < password.length(); i++) {
        hash = ((hash << 5) + hash) + password[i];
    }

    return hash;
}

class User {
protected:
    string name;
    string ID;
    string email;
    string permissions[5];
    int perm_count;
    unsigned long hashed_password;

public:
    User(string n, string i, string e, string pwd, string perms[], int count)
        : name(n), ID(i), email(e), perm_count(count), hashed_password(generateHash(pwd)) {
        for (int j = 0; j < count; j++) {
            permissions[j] = perms[j];
        }
    }

    virtual void display() {
        cout << "Name: " << name << "\nID: " << ID << "\nEmail: " << email << endl;
    }

    bool authenticate(const string& password) {
        return hashed_password == generateHash(password);
    }

    virtual void accessLab() {
        for (int i = 0; i < perm_count; i++) {
            if (permissions[i] == "full_lab_access") {
                cout << name << " has access to the lab." << endl;
                return;
            }
        }
        cout << name << " does not have lab access." << endl;
    }

    bool hasPermission(const string& action) {
        for (int i = 0; i < perm_count; i++) {
            if (permissions[i] == action) return true;
        }
        return false;
    }
};

class Student : public User {
protected:
    int assignments[5];

public:
    Student(string n, string i, string e, string pwd)
        : User(n, i, e, pwd, new string[1]{"submit assignment"}, 1) {
        for (int i = 0; i < 5; i++) assignments[i] = 0;
    }

    void submitAssignment(int index) {
        if (index >= 0 && index < 5) {
            assignments[index] = 1;
            cout << name << " submitted assignment " << index << "." << endl;
        }
    }

    void display() override {
        User::display();
        cout << "Role: Student\nAssignments: ";
        for (int i = 0; i < 5; i++) cout << assignments[i] << " ";
        cout << endl;
    }
};

class TA : public Student {
    Student* assignedStudents[10];
    int studentCount;
    string projects[2];
    int projectCount;

public:
    TA(string n, string i, string e, string pwd)
        : Student(n, i, e, pwd), studentCount(0), projectCount(0) {
        string perms[] = {"submit assignment", "view projects", "manage_students"};
        for (int j = 0; j < 3; j++) {
            permissions[j] = perms[j];
        }
        perm_count = 3;
    }

    void display() override {
        User::display();
        cout << "Role: TA\nStudents Managed: " << studentCount << "\nProjects: ";
        for (int i = 0; i < projectCount; i++) cout << projects[i] << " ";
        cout << endl;
    }

    void addProject(const string& project) {
        if (projectCount < 2) {
            projects[projectCount++] = project;
            cout << name << " started project: " << project << endl;
        } else {
            cout << "Project limit reached." << endl;
        }
    }

    void assignStudent(Student* s) {
        if (studentCount < 10) {
            assignedStudents[studentCount++] = s;
            cout << "Student assigned to TA " << name << "." << endl;
        } else {
            cout << "TA already manages 10 students." << endl;
        }
    }
};

class Professor : public User {
public:
    Professor(string n, string i, string e, string pwd)
        : User(n, i, e, pwd, new string[2]{"assign projects", "full_lab_access"}, 2) {}

    void display() override {
        User::display();
        cout << "Role: Professor" << endl;
    }

    void assignProjectToTA(TA* ta, const string& project) {
        if (ta->hasPermission("view projects")) {
            ta->addProject(project);
        } else {
            cout << "TA does not have permission to view projects." << endl;
        }
    }
};

void authenticateAndPerformAction(User* user, const string& action) {
    if (user->hasPermission(action)) {
        cout << "Action '" << action << "' performed by " << endl;
        user->display();
    } else {
        cout << "Permission denied for action: " << action << endl;
    }
}

int main() {
    Student s1("Alizeh", "S1123", "alizeh@uni.edu", "pass423");
    TA ta1("Sarim", "T4536", "sarim@sity.edu", "secure443");
    Professor p1("Dr. Khaqan", "P7849", "khaqan@ver.edu", "admin729");

    s1.display();
    cout<<endl;
    ta1.display();
    cout<<endl;
    p1.display();
    
    cout << "Student Authentication: " << s1.authenticate("pass423") << endl;
    cout << "TA Authentication: " << ta1.authenticate("wrongpass") << endl;

    s1.accessLab();
    p1.accessLab();

    authenticateAndPerformAction(&s1, "submit assignment");
    authenticateAndPerformAction(&ta1, "manage_students");
    authenticateAndPerformAction(&p1, "assign projects");

    s1.submitAssignment(1);
    ta1.assignStudent(&s1);
    p1.assignProjectToTA(&ta1, "Computer Science");

    return 0;
}
