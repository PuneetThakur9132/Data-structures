#include <iostream>

using namespace std;

template <typename T>
class Node{
public:
    T data;
    Node<T>*next;

    Node(T data){
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class stackUsingLL{
    Node<T>*head;
    int size;
public:
    stackUsingLL(){
        head = NULL;
        size = 0;
    }

    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size==0;
    }
    void push(T element){
        Node<T>*newNode = new Node<T>(element);
        newNode->next = head;
        head = newNode;
        size++;
    }
    T pop(){
        if(isEmpty()){
            cout<<"Stack empty"<<endl;
            return 0;
        }
        T ans = head->data;
        Node<T>*temp = head;
        head = head->next;
        delete temp;
        size--;
        return ans;
    }
    T top(){
        if(isEmpty()){
            return 0;
        }
        T ans = head->data;
        return ans;

    }
};

int main(){
    stackUsingLL<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout<<s.top()<<endl;
    cout<<s.getSize()<<endl;
    cout<<s.isEmpty()<<endl;

    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;

}
