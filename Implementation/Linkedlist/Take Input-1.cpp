#include <iostream>

using namespace std;



class Node{
public:
    int data;
    Node*next;

    Node(int data){
        this->data = data;
        next = NULL;

    }

};
void print(Node*);
//Node* takeInput1();
Node* takeInput2();

int main(){

    Node*head = takeInput2();
    print(head);

}

void print(Node*head){
    Node*temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

//In this aproach of taking Input time complexity is O(n^2)

/*Node* takeInput1(){
    int data;
    cin>>data;
    Node*head = NULL;
    while(data!= -1){
      Node*newNode = new Node(data);
      if(head==NULL){
        head = newNode;
      }
      else{
        Node*temp = head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next = newNode;
        cin>>data;
      }
    }

    return head;

}*/


//Time complexity of this approach is O(n).It is improved approach and we will use this more often for taking the input.

Node* takeInput2(){
    int data;
    cin>>data;
    Node*head = NULL;
    Node*tail = NULL;
    while(data!=-1){
        Node*newNode = new Node(data);
        if(head==NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = tail->next;

        }
        cin>>data;
    }

    return head;
}
