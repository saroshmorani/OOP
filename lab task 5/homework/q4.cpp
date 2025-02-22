#include<iostream>
#include<cstdlib>
#include<thread>
#include<chrono>
using namespace std;

class Blend{
    public:
    void blend_juice(){
        cout<<"selecting the fruits and blending"<<endl;
        std::this_thread::sleep_for(std::chrono::seconds(5));
        cout<<"juice is blended"<<endl;
    }
};

class Grind{
    public:
    void grind_juice(){
        cout<<"grinding the juice"<<endl;
        std::this_thread::sleep_for(std::chrono::seconds(5));
        std::cout << "Juice is grinded"<<endl;
    }
};

class Juice_Maker{
    private:
    Blend blender;
    Grind grinder;

    public:
    void juice(){
        blender.blend_juice();
        grinder.grind_juice();
        cout<<"The Juice is ready!!"<<endl;
    }
};
int main(){
    Juice_Maker berry_blast;
    berry_blast.juice();
}