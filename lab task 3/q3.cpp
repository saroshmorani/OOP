#include<iostream>
using namespace std;

void resizeArray(int*&arr,int&capacity){
    int newCapacity=capacity*2;
    int*newArr=new int[newCapacity];
    for(int i=0;i<capacity;i++){
        newArr[i]=arr[i];
    }
    delete[]arr;
    arr=newArr;
    capacity=newCapacity;
}

int main(){
    int capacity=5,count=0,n,value;
    int*arr=new int[capacity];

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>value;
        if(count==capacity){
            resizeArray(arr,capacity);
        }
        arr[count++]=value;
    }

    int*finalArr=new int[count];
    for(int i=0;i<count;i++){
        finalArr[i]=arr[i];
    }
    delete[]arr;
    arr=finalArr;

    for(int i=0;i<count;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    delete[]arr;
    return 0;
}
