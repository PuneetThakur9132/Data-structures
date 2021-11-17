#include <iostream>
#include <climits>


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
            cout<<"stack full"<<endl;
            return;
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

int main(){
    stackUsingArray s(5);

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;

    s.push(9);
    cout<<s.top()<<endl;
    cout<<s.size()<<endl;
    cout<<s.isEmpty()<<endl;

    s.push(22);
    s.push(21);

}
