#include <iostream>
using namespace std;

template <typename T>
class QueueUsingArray{
    T*data;
    int firstIndex; // to keep the index of front index
    int nextIndex; // to keep the index of where we've to add next element
    int size;
    int capacity;

public:
    QueueUsingArray(int s){
        data = new T[s];
        firstIndex = -1;
        nextIndex = 0;
        size = 0;
        capacity = s;
    }

    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size==0;
    }
    void enqueue(T element){
        if(size == capacity){
            T*newData = new T[2*capacity];
            int j=0;
            for(int i=firstIndex;i<capacity;i++){
                newData[j] = data[i];
                j++;
            }
            for(int i=0;i<firstIndex;i++){
                newData[j]=data[i];
                j++;
            }
            capacity *= 2;
            delete[] data;
            data = newData;
            firstIndex=0;
            nextIndex=capacity;


        }
        data[nextIndex] = element;
        nextIndex = (nextIndex+1)%capacity;
        if(firstIndex == -1){
            firstIndex=0;
        }
        size++;
    }
    T front(){
        if(size==0){
            cout<<"queue is empty"<<endl;
            return 0 ;
        }
        T ans = data[firstIndex];
        return ans;
    }
    T dequeue(){
        if(size==0){
            cout<<"queue is empty"<<endl;
            return 0 ;
        }
        T ans = data[firstIndex];
        firstIndex = (firstIndex+1)%capacity;
        size--;
        if(size==0){
            firstIndex=-1;
            nextIndex=0;
        }
        return ans;

    }

};

int main(){
    QueueUsingArray<int> q1(4);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.enqueue(50);

     cout<<q1.front()<<endl;
     cout<<q1.getSize()<<endl;

    cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue()<<endl;

     cout<<q1.getSize()<<endl;
    cout<<q1.front()<<endl;
}
