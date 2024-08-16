 #include<bits/stdc++.h>
#include<queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

 int leftheight(Node* root){
        int h=0;
        while(root!=NULL){
            h++;
            root=root->left;
        }
        return h;
    }
    
    int rightheight(Node* root){
        int h=0;
        while(root!=NULL){
            h++;
            root=root->right;
        }
        return h;
    }
 int countNodes(Node* root) {
        // Write your code here
        if(root==NULL) return 0;
        int lh=leftheight(root);
        int rh=rightheight(root);
        if(lh==rh) return (1<<lh)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
    
 int main(){
    Node* root = new Node(15);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(25);
    root->left->right = new Node(35);
    cout<<countNodes(root);
    return 0;
}