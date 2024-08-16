#include<bits/stdc++.h>
#include<queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

int isSumProperty(Node *root)
    {
        if(root==NULL) return 1;
        if(!root->left && !root->right) return 1;
        int sum=0;
        if(root->left!=NULL)sum+=root->left->data;
        if(root->right!=NULL) sum+=root->right->data;
        
        if(root->data!=sum) return 0;
        
       bool l= isSumProperty(root->left);
       bool r= isSumProperty(root->right); 
       return l&&r;
    }

    int main(){
    Node* root = new Node(15);
    root->left = new Node(10);
    root->right = new Node(5);
    root->left->left = new Node(5);
    root->left->right = new Node(5);
    cout<<isSumProperty(root);
    return 0;
}