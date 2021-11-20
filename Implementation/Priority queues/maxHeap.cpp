#include <iostream>
#include <vector>

using namespace std;

class PriorityQueue{
    vector<int>pq;

public:
    int getSize(){
        return pq.size();
    }
    bool isEmpty(){
        return pq.size()==0;
    }

    int getMax(){
        if(isEmpty()){
            return 0;
        }

        return pq[0];
    }
    void insert(int element){
        pq.push_back(element);
        int childIndex = pq.size()-1;

        //UP - HEAPIFY
        while(childIndex > 0){
            int parentIndex = (childIndex-1)/2;

            if(pq[childIndex] > pq[parentIndex]){
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else{
                break;
            }
            childIndex = parentIndex;
        }
    }
    int RemoveMax(){
        if(isEmpty()){
            return 0;
        }
        int ans = pq[0];
        pq[0] = pq[pq.size()-1];
        pq.pop_back();

        int parentIndex = 0;
        int leftChildIndex = 2*parentIndex+1;
        int rightChildIndex = 2*parentIndex +2;

        //DOWN HEAPIFY
        while(leftChildIndex < pq.size()){
            int minIndex = parentIndex;

            if(pq[minIndex] < pq[leftChildIndex]){
                minIndex = leftChildIndex;
            }
            if(rightChildIndex<pq.size() && pq[minIndex] < pq[rightChildIndex]){
                minIndex = rightChildIndex;
            }
            if(minIndex == parentIndex){
                break;
            }

            int temp = pq[parentIndex];
            pq[parentIndex] = pq[minIndex];
            pq[minIndex] = temp;

            parentIndex = minIndex;
            leftChildIndex = 2*parentIndex+1;
            rightChildIndex = 2*parentIndex+2;

            }

            return ans;
    }
};

int main(){
    PriorityQueue pq;

    pq.insert(100);
    pq.insert(50);
    pq.insert(60);
    pq.insert(20);
    pq.insert(25);
    pq.insert(55);
    pq.insert(65);

    cout<<"SIZE:"<<" "<<pq.getSize()<<endl;
    cout<<"MAX:"<<" "<<pq.getMax()<<endl;

    cout<<"REMOVED:"<<" "<<pq.RemoveMax()<<endl;
    cout<<"REMOVED:"<<" "<<pq.RemoveMax()<<endl;
    cout<<"REMOVED:"<<" "<<pq.RemoveMax()<<endl;

}
