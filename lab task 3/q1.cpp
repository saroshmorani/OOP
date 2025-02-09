#include<iostream>
using namespace std;

class User{
    public:
    int age;
    string name;
};

int main(int argc, char *argv[]){
    if(argc<3){
        cout<<"Invalid";
    }

    User user1;
    user1.name=argv[1];
    user1.age=stoi(argv[2]);

    cout<<"My name is "<<user1.name<<" and I'm "<<user1.age<<" years old.";
}