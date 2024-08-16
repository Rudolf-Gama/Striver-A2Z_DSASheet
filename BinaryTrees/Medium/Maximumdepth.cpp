#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
int height(struct Node* node){
        // code here 
        if(node==NULL)
        return 0;
        int lh=height(node->left);
        int rh=height(node->right);
        return 1+max(lh,rh);
    }
/*
Input:
           1
         /    \
       2       3
      /   \
    4     5
            \
            6
Output: 4 
*/
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right=new Node(6);
    
    cout<<height(root);
    
    return 0;
}