#include<iostream>
#include<cstdlib>
using namespace std;

void add(void* array, int Size){
    int* intarray=(int*)array;
    for(int i=0; i<Size; i++){
        intarray[i]+=15; 
    }
}

int main(int argc, char* argv[]){
    int size=argc-1;
    int arr[size];
    void*ptr=arr;

    for(int i=0; i<size; i++){
        arr[i]=atoi(argv[i+1]);
    }

    add(arr, size);
    cout<<"the modified array is: {";
    for(int i=0; i<size; i++){
        cout<<arr[i];
        if (i < size - 1) cout << " ";} 
    cout<<"}"<<endl;
return 0;
}