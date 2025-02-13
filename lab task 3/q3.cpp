#include <iostream>
using namespace std;

class Glass {
public:
    int LiquidLevel;
    
    Glass() {
        LiquidLevel = 200;
    }
    
    void Drink(int ml) {
        if (ml> 0 && ml<= LiquidLevel) {
            LiquidLevel -= ml;
            cout<<"Drank "<<ml<<" ml."<<endl;
            cout<<"Remaining: "<<LiquidLevel<<" ml."<<endl;
            
            if (LiquidLevel<100) {
                Refill();
            }
        } else {
            cout<<"Liquid is more 100ml."<<endl;
        }
    }
    
    void Refill() {
        LiquidLevel=200;
        cout << "Glass is refilled to 200 ml."<<endl;
    }
};

int main() {
    Glass myGlass;
    string command;
    int amount;
    
    while (true) {
        cout<<"Enter command (drink/ exit): ";
        cin>>command;
        
        if (command=="exit") {
            break;
        }
        else if(command=="drink"){
            cin>>amount;
            myGlass.Drink(amount);
        }
    }
    
    return 0;
}
