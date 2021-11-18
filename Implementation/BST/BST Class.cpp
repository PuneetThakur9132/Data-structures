/**********************************************************

	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};
	
***********************************************************/

class BST {
    // Define the data members
    BinaryTreeNode<int>*root;
    
    
   private:
     bool search(BinaryTreeNode<int>*node , int data){
         if(node==NULL){
             return false;  // means tree doesn't exist
         }
         if(node->data == data){
             return true;
         }
         
         if(node->data > data){
             return search(root->left , data);
         }
         
         if(node->data < data){
             return search(root->right , data);
         }
         
     }
     BinaryTreeNode<int>* insert(BinaryTreeNode<int>*node , int data){
         
         if(node==NULL){
             BinaryTreeNode<int>*newNode = new BinaryTreeNode<int>(data);
             return newNode;
         }
         
        if(node->data < data){
            BinaryTreeNode<int>*rightnode = insert(node->right , data);
            node->right = rightnode;
        }
        if(node->data >= data){
            BinaryTreeNode<int>*leftnode = insert(node->left , data);
            node->left = leftnode;
        }
         
        return node;
         
     }
    
    BinaryTreeNode<int>*remove(BinaryTreeNode<int>*node , int data){
        if(node == NULL){
            return NULL;
        }
        
        if(node->data == data){
            if(node->left==NULL && node->right==NULL){
                delete node;
                return NULL;
            }
            else if(node->left==NULL){
                BinaryTreeNode<int>*temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            }
            else if(node->right == NULL){
                BinaryTreeNode<int>*temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            }
            else{
                BinaryTreeNode<int>*minNodeRight = node->right;
                while(minNodeRight->left!=NULL){
                    minNodeRight = minNodeRight->left;
                }
                
                int temp = node->data;
                node->data = minNodeRight->data;
                minNodeRight->data = temp;
                
                node->right = remove(node->right , temp);
                
                return node;
                
            }
        }
        
        if(node->data < data){
            node->right = remove(node->right , data);
        }
        
        if(node->data > data){
            node->left = remove(node->left , data);
        }
        
        return node;
        
    }
    
    void print(BinaryTreeNode<int>*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<":";
    
    if(root->left !=NULL){
        cout<<"L"<<":"<<root->left->data<<",";
    }
    
    if(root->right !=NULL){
        cout<<"R"<<":"<<root->right->data;
    }
    cout<<endl;
    print(root->left);
    print(root->right);
}
    
   public:
    BST() { 
        // Implement the Constructor
        root = NULL;
    }
    ~BST(){
        delete root;
    }

	/*----------------- Public Functions of BST -----------------*/

    void remove(int data) { 
        // Implement the remove() function 
        
        this->root = remove(root , data);
    }

    void print() { 
        // Implement the print() function
        
        print(root);
    }

    void insert(int data) { 
        // Implement the insert() function 
        this->root = insert(root , data);
    }

    bool search(int data) {
		// Implement the search() function
        return search(root , data);
        
    }
};