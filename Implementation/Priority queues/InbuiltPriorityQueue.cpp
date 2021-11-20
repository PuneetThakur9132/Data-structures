#include <iostream>
#include <queue>

using namespace std;

int main(){
    priority_queue<int> pq;
    pq.push(100);
    pq.push(50);
    pq.push(60);
    pq.push(20);
    pq.push(25);
    pq.push(55);
    pq.push(65);

    cout<<"SIZE:"<<" "<<pq.size()<<endl;
    cout<<"MAX:"<<" "<<pq.top()<<endl;

    pq.pop();
    cout<<"MAX:"<<" "<<pq.top()<<endl;

     pq.pop();
    cout<<"MAX:"<<" "<<pq.top()<<endl;

      pq.pop();
    cout<<"MAX:"<<" "<<pq.top()<<endl;
}
