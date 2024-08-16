#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
int height(Node* node,int &dia){
        // code here 
        if(node==NULL)
        return 0;
        int lh=height(node->left,dia);
        int rh=height(node->right,dia);
        
        dia=max(dia,lh+rh+1);
        return 1+max(lh,rh);
    }
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        // Your code here
        int dia=0;
        height(root,dia);
        return dia;
    }
/*
          10
        /   \
      20    30
    /   \ 
   40   60
   output :4
*/

int heightBF(Node* node){
        // code here 
        if(node==NULL)
        return 0;
        int lh=heightBF(node->left);
        int rh=heightBF(node->right);
        
        return 1+max(lh,rh);
    }
    // Function to return the diameter of a Binary Tree.
    int dia=0;
    
    int diameterBF(Node* root) {
        // Your code here
        if(root==NULL ) return 0;
        int lh=heightBF(root->left);
        int rh=heightBF(root->right);
        dia=max(dia,lh+rh+1);
        diameterBF(root->left);
        diameterBF(root->right);
        return dia;
    }

int main(){
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(60);
    
    cout<<diameter(root);
    return 0;
}