#include<iostream>
#include<cstdlib>
using namespace std;

int main(int argc, char* argv[]){
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <size> <values...>" << endl;
        return 1;
    }
    int size=argc-1;
    float arr[size];
    float *ptr=arr;
    float sum=0;

    for(int i=0; i<size; i++){
        arr[i]=atof(argv[i+1]);
    }
    
    for(int i=0; i<size; i++){
        sum+= (*ptr+i);
    }
    cout<<"The sum is: "<<sum<<endl;
    return 0;
}