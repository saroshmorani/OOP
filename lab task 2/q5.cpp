#include<iostream>
#include<vector>
using namespace std;

struct Person{
    int id;
    string name;
    };

void sortByID(vector<Person>&people){
    int n=people.size();
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(people[j].id>people[j+1].id) swap(people[j],people[j+1]);
        }
    }
}

void sortByName(vector<Person>&people){
    int n=people.size();
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(people[j].name[0]>people[j+1].name[0]) swap(people[j],people[j+1]);
        }
    }
}

int main(){
    int N;
    cin>>N;
    vector<Person>people(N);
    for(int i=0;i<N;i++) cin>>people[i].id>>people[i].name;

    sortByID(people);
    cout<<"\nSorted by ID:\n";
    for(const auto&p:people) cout<<"ID: "<<p.id<<", Name: "<<p.name<<endl;

    sortByName(people);
    cout<<"\nSorted by First Character of Name:\n";
    for(const auto&p:people) cout<<"ID: "<<p.id<<", Name: "<<p.name<<endl;

    return 0;
}
