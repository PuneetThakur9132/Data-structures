#include <iostream>
#include <queue>

using namespace std;

template <typename T>
class BinaryTreeNode{
public:
    T data;
    BinaryTreeNode*left;
    BinaryTreeNode*right;

    BinaryTreeNode(T data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

BinaryTreeNode<int>*takeInput();
void print(BinaryTreeNode<int>*);

int main(){

    BinaryTreeNode<int>*root = takeInput();
    print(root);

}

BinaryTreeNode<int>*takeInput(){

    queue<BinaryTreeNode<int>*>pendingnodes;
    int rootData;
    cout<<"Enter root Data"<<endl;
    cin>>rootData;

    BinaryTreeNode<int>*root = new BinaryTreeNode<int>(rootData);
    pendingnodes.push(root);

    while(pendingnodes.size()!=0){
        BinaryTreeNode<int>*front = pendingnodes.front();
        pendingnodes.pop();

        int leftChildData , rightChildData;
        cout<<"Enter left child of"<<" "<<front->data<<endl;
        cin>>leftChildData;

        if(leftChildData!=-1){
            BinaryTreeNode<int>*leftChild = new BinaryTreeNode<int>(leftChildData);
            front->left = leftChild;
            pendingnodes.push(leftChild);
        }
        cout<<"Enter right child of"<<" "<<front->data<<endl;
        cin>>rightChildData;
        if(rightChildData!=-1){
            BinaryTreeNode<int>*rightChild = new BinaryTreeNode<int>(rightChildData);
            front->right = rightChild;
            pendingnodes.push(rightChild);
        }
    }

    return root;



}

void print(BinaryTreeNode<int>*root){
     queue<BinaryTreeNode<int>*>pendingnodes;

    pendingnodes.push(root);

    while(pendingnodes.size()!=0){

        BinaryTreeNode<int>*front = pendingnodes.front();
        pendingnodes.pop();

        cout<<front->data<<":";

        if(front->left!=NULL){
            cout<<"L"<<":"<<front->left->data<<",";
            pendingnodes.push(front->left);
        }
        else{
            cout<<"L"<<":"<<"-1"<<",";
        }

        if(front->right!=NULL){
            cout<<"R"<<":"<<front->right->data;
            pendingnodes.push(front->right);
        }else{
             cout<<"R"<<":"<<"-1";
        }
        cout<<endl;


    }

}
