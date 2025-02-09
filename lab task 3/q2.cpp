#include<iostream>
using namespace std;

class Date{
    private:
    int month;
    int day;
    int year;

    public:
    void set_date(int M, int D, int Y){
        month=M;
        day=D;
        year=Y;
    }

    void display_date(){
        cout<<month<<"/"<<day<<"/"<<year<<endl;
    }
};

int main(int argc, char* argv[]){
    if(argc<3){
        cout<<"Invalid";
    }

    Date date1;
    date1.set_date(stoi(argv[1]), stoi(argv[2]), stoi(argv[3]));
    date1.display_date();

    return 0;
}