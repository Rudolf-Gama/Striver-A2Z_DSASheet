
        #include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

Node* LCA(Node *root, int n1, int n2)
        {
            // code here
            if(root==NULL) return root;
            
            if(root->data>n1 && root->data>n2){
                return LCA(root->left,n1,n2);
            }
            if(root->data<n1 && root->data<n2){
                return LCA(root->right,n1,n2);
            }
            return root;
        }
Node* Rightmost(Node * root){
    if(root->right==NULL){
        return root;
    return Rightmost(root->right);
    }
}

Node* helper(Node * root){
    if(root->left==NULL){
        return root->right;
    }else if(root->right==NULL){
        return root->left;
    }
    Node* Rightchild=root->right;
    Node* rMost=Rightmost(root->left);
    rMost->right=Rightchild;
    return root->left;
}
 
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

Node* insert(Node* node, int data) {
            // Your code goes here
            if(node==NULL) return new Node(data);
            Node* root=node;
            while(root){
                if(root->data==data) break;
                if(root->data>data){
                    if(root->left!=NULL)
                       root=root->left;
                    else {
                        root->left=new Node(data);
                        break;
                    }
                }
                else{
                    if(root->right!=NULL) 
                    root=root->right;
                    else{
                        root->right=new Node(data);
                        break;
                    }
                }
            }
        return node;
    }

int main() {
    Node* root = NULL;
    root = insert(root, 4);
    insert(root, 2);
    insert(root, 7);
    insert(root, 1);
    insert(root, 3);
    insert(root, 6);
    insert(root, 8);
    insert(root,2);  //not added since duplicate
    cout << "Inorder traversal of the BST: ";
    inorder(root);
    cout << endl;
    
    cout<<LCA(root,3,6)->data;
    return 0;
}