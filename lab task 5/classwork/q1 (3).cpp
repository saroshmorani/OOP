#include<iostream>
#include<cstdlib>
using namespace std;

class Engine{

    public:
    bool isRunning;
    Engine(){
        isRunning=false;
        cout<<"Engine is Constructed"<<endl;
    }
    void start(){
        isRunning=true;
        cout<<"Engine Started"<<endl;
    }

    void stop(){
        isRunning=false;
        cout<<"Engine Stopped"<<endl;
    }
    ~Engine(){
        cout<<"The Engine is Destructed"<<endl;
    }

};

class Car{
    private:
    Engine engine;

    public:
    Car(){
        cout<<"Car is Constructed"<<endl;
    }
    void startCar(){
        engine.start();
    }

    void stopCar(){
        engine.stop();
    }
    ~Car(){
        cout<<"The Car is Destructed"<<endl;
    }
};

int main(){
    Car haval;
    haval.startCar();
    haval.stopCar();
}