#include <iostream>
#include "stackUsingarray.h"

using namespace std;

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

}
