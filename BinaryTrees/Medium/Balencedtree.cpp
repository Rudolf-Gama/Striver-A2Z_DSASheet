#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
int height(Node* node){
        // code here 
        if(node==NULL)
        return 0;
        int lh=height(node->left);
        int rh=height(node->right);
        if(lh==-1 || rh==-1) return -1;
        if(abs(lh-rh)>1) return -1;
        return 1+max(lh,rh);
    }
    bool isBalanced(Node *root)
    {
        //  Your Code here
        return height(root)!=-1;
    }
   /*

     1
    /  \
   2    3
    \
     5 
      \
       6

   */ 
  //0 not balanced  , 1 balanced 

  int calheight(Node* node){
        // code here 
        if(node==NULL)
        return 0;
        int lh=height(node->left);
        int rh=height(node->right);
        
        return 1+max(lh,rh);
    }
    bool isBalancedBF(Node *root)
    {
        //  Your Code here
        if(root==NULL) return true;
        
        int lh=calheight(root->left);
        int rh=calheight(root->right);
        
        if(abs(lh-rh)<=1 && isBalancedBF(root->left) && isBalancedBF(root->right))
        return true;
        
        return false;
    }
    
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);

    cout<<isBalanced(root);
    
    return 0;
}