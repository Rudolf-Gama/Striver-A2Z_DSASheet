#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

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
Node *deleteNode(Node *root, int X) {
    // your code goes here
    if(root==NULL) return root;
    if(root->data==X)
     return helper(root);
    Node* dummy=root;
    while(root){
        if(root->data>X){
            if(root->left!=NULL && root->left->data==X){
              root->left=helper(root->left);
               break;
             }
            else root=root->left;
        }
        else
        {
            if(root->right!=NULL && root->right->data==X){
              root->right=helper(root->right);
               break;
             }
            else root=root->right;
        }
    }
    return dummy;
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
    
    deleteNode(root,7);
    cout << "Inorder traversal of the BST: ";
    inorder(root);
    cout << endl;
    
    return 0;
}