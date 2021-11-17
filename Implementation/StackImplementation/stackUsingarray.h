#ifndef STACKUSINGARRAY_H_INCLUDED
#define STACKUSINGARRAY_H_INCLUDED

#include<iostream>
#include<climits>

using namespace std;

class stackUsingArray{
    int*data;
    int nextIndex;
    int capacity;

public:
    stackUsingArray(int totalsize){
        data = new int[totalsize];
        nextIndex = 0;
        capacity = totalsize;
    }

    int size(){
        return nextIndex;
    }
    bool isEmpty(){
        return nextIndex==0;
    }
    void push(int element){
        if(nextIndex == capacity){
            int* newData = new int[2*capacity];
            for(int i=0 ; i<capacity ; i++){
                newData[i] = data[i];
            }
            capacity *= 2;
            delete[] data;
            data = newData;
        }
        data[nextIndex] = element;
        nextIndex++;
    }
    int pop(){
        if(isEmpty()){
          cout<<"stack is Empty"<<endl;
          return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }
    int top(){
        if(isEmpty()){
          cout<<"stack is Empty"<<endl;
          return INT_MIN;
        }
        return data[nextIndex-1];
    }

};



#endif // STACKUSINGARRAY_H_INCLUDED
