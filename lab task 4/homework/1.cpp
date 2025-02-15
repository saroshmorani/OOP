#include<iostream>
#include<cmath>
#include<stdlib.h>
using namespace std;

class Circle{
    private:
    double radius;

    public:
    Circle(double r){
        radius=r;
    }

    void get_Area(){
        double area;
        area=M_PI*radius*radius;
        cout<<"Area: "<<area<<endl;
    }

    void get_Perimeter(){
        double perimeter;
        perimeter=2*M_PI*radius;
        cout<<"Perimeter: "<<perimeter<<endl;
    }
};

int main(int argc, char *argv[]){
    if(argc<2){
        return 1;
    }
    double r=stod(argv[1]);

    Circle c1(r);

    c1.get_Area();
    c1.get_Perimeter();

    return 0;
}