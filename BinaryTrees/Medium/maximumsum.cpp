#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

 int findsum(Node* root,int &maxi){
        if(root==NULL) return 0;
        int lsum=max(findsum(root->left,maxi),0);
        int rsum=max(findsum(root->right,maxi),0);
        maxi=root->data+lsum+rsum;
        return root->data+max(lsum,rsum);
    }
    int findMaxSum(Node* root)
    {
        // Your code goes here
        int maxi=INT_MIN;
        findsum(root,maxi);
        return maxi;
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
    
    cout<<findMaxSum(root);
    return 0;
}