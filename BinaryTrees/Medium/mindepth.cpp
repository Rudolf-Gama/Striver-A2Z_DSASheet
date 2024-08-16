#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int minDepth(Node *root) {
        // Your code here
        if(root==NULL) return 1e9;
        if(root->left==NULL && root->right==NULL)
        return 1;
        
        int l=minDepth(root->left);
        int r=minDepth(root->right);
        return 1+min(l,r);
    }
/*
          10
        /   \
      20    30
    /   \ 
   40   60
   output :2
*/

    int main(){
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(60);
    
    cout<<minDepth(root);
    return 0;
}