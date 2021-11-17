/**********************Implementation of linkedList**********************************/
#include <iostream>

using namespace std;

//Node class
class Node{
public:
    int data;
    Node*next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

void print();
Node*takeInput();
Node* insert(Node* , int , int );
Node*delete(Node* , int );

int main(){
    Node*head = takeInput();
    print();
    int data , i;
    cin>>data;
    head = insert(head , i , data);
    int pos;
    cin>>pos;
    head = delete(head , pos);
}
void print(){
    Node*temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

Node*takeInput(){
    int data;
    cin>>data;
    Node*head = NULL;
    Node*tail = NULL;
    while(data!=-1){
     Node*newNode = new Node(data);
     if(head==NULL){
        head=newNode;
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

Node* insert(Node*head , int i , int data){
    Node*newNode = new Node(data);
    int count = 0;
    Node*temp = head;
    if(i==0){
        newNode->next = head;
        head = newNode;
        return head;
    }
    while(temp!=NULL && count<i-1){
        count++;
        temp=temp->next;
    }
    if(temp!=NULL){
        Node*a = temp->next;
        temp->next = newNode;
        newNode->next = a;

    }

    return head;

}

Node*delete(Node*head , int pos){
    Node*temp = head;
    int count = 0;
    if(pos==0){
        Node*a = head;
        head = head->next;
        delete a;
        return head;
    }
    while(temp!=NULL && count<pos-1){
        temp = temp->next;
        count++;
    }
    if(temp!=NULL && temp->next!=NULL){
        Node*a = temp->next;
        temp->next = a->next;
        delete a;
    }
    return head;


}
