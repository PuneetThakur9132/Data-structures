#include <iostream>
#include <vector>
#include <queue>

using namespace std;

template <typename T>
class TreeNode{
public:
    T data;
    vector<TreeNode*>children; // vector of TreeNode pointers , because in this vector we want to store address of childs of TreeNode

    TreeNode(T data){
        this->data = data;
    }
    ~TreeNode(){
         for(int i=0 ;i<children.size();i++){
               delete children[i];
         }
    }
};

TreeNode<int>* takeInput();
void print(TreeNode<int>* );



int main(){

    TreeNode<int>*root = takeInput();
    print(root);
}

TreeNode<int>* takeInput(){
    int rootData;
    cout<<"Enter Data"<<endl;
    cin>>rootData;

    TreeNode<int>*root = new TreeNode<int>(rootData);
    int n;
    cout<<"Enter num of chidren of"<<rootData<<endl;
    cin>>n;

    for(int i=0;i<n;i++){
        TreeNode<int>*child = takeInput();
        root->children.push_back(child);
    }

    return root;
}

void print(TreeNode<int>* root){

    queue<TreeNode<int>*>pendingnodes;

    pendingnodes.push(root);

    while(pendingnodes.size()!=0){
        TreeNode<int>*front = pendingnodes.front();
        pendingnodes.pop();

        cout<<front->data<<":";
        for(int i=0;i<front->children.size();i++){
            if(i == (front->children.size()-1)){
                 cout<<front->children[i]->data;
            }else{
                cout<<front->children[i]->data<<",";
            }



            pendingnodes.push(front->children[i]);
        }
        cout<<endl;
    }

}
