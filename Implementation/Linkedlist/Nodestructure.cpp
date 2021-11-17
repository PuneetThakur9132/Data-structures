#include <iostream>

using namespace std;

/**********Linked list Node Structure*********/

class Node{
public:
    int data;
    Node*next;

    Node(int data){
        this->data = data;
        next = Null;
    }
};
int main()
{
    Node n1(1);
    Node*head = &n1;

    Node n2(2);
    n1.next = &n2;

    Node n3(3);
    n2.next = &n3;
    return 0;
}
