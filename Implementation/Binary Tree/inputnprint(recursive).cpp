#include <iostream>

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
    int rootData;
    cout<<"Enter Data"<<endl;
    cin>>rootData;

    if(rootData == -1){
        return NULL;
    }

    BinaryTreeNode<int>*root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>*leftChild = takeInput();
    BinaryTreeNode<int>*rightChild = takeInput();

    root->left = leftChild;
    root->right = rightChild;

    return root;
}

void print(BinaryTreeNode<int>*root){

    if(root==NULL){
        return;
    }
    cout<<root->data<<":";

    if(root->left!=NULL){
        cout<<"L"<<root->left->data;
    }
    if(root->right!=NULL){
        cout<<"R"<<root->right->data;
    }
    cout<<endl;
    print(root->left);
    print(root->right);
}
