#include<iostream>
#include<vector>
using namespace std;

struct Subject{
    string name;
    };

struct Student{
    int id;
    Subject subjects[3];
    };

int main(){
    int numStudents;
    cin>>numStudents;
    vector<Student>students(numStudents);

    for(int i=0;i<numStudents;i++){
        cin>>students[i].id;
        for(int j=0;j<3;j++){
        cin>>students[i].subjects[j].name;
        }
    }

    for(const auto&student:students){
        cout<<"ID:"<<student.id<<"\nSubjects:";
        for(const auto&subj:student.subjects) 
        cout<<subj.name<<" ";
        cout<<endl;
    }
    return 0;
}
