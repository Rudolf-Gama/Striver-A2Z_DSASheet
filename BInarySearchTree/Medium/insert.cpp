#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

Node* insertRE(Node* node, int data) {
            // Your code goes here
            if(node==NULL) return new Node(data);
            if(node->data==data) return node;
            if(node->data<data){
                node->right=insertRE(node->right,data);
            }
            else {
                node->left=insertRE(node->left,data);
            }
        return node;
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

    return 0;
}