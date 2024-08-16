#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};



bool helper(Node* L,Node* R){
        if(!L || !R) return L==R;
        
        if(L->data != R->data) return false;
        
        return helper(L->left,R->right) &&
               helper(L->right,R->left);
    }
    bool isSymmetric(struct Node* root)
    {
	    // Code here
	    if(root==NULL) return true;
	    return helper(root->left,root->right);
    }

int main(){
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(20);
    root->left->left = new Node(30);
    root->right->right = new Node(30);
    cout<<isSymmetric(root);
    return 0;
}