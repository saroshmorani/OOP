#include <iostream>
using namespace std;

class Student {
private:
    const int roll_no; 

public:
    
    Student() : roll_no(0) {}

   
    void setRollNo(int roll) {
       
        int* ptr = const_cast<int*>(&roll_no);
        *ptr = roll;
    }

    void display() {
        cout << "Student Roll No: " << roll_no << endl;
    }
};

int main() {
    Student s;
    int roll = 324765;
    s.setRollNo(roll);
    s.display();
    return 0;
}
