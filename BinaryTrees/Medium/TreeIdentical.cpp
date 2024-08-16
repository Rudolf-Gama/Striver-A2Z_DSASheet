#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
bool isIdentical(Node *r1, Node *r2)
    {
        //Your Code here
        if(r1==NULL || r2==NULL) return (r1==r2);
        
        return (r1->data==r2->data) &&
               isIdentical(r1->left,r2->left) &&
               isIdentical(r1->right,r2->right);
    }

    int main(){
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(60);

    Node* root1 = new Node(10);
    root1->left = new Node(20);
    root1->right = new Node(30);
    root1->left->left = new Node(40);
    root1->left->right = new Node(60);
    
    cout<<isIdentical(root,root1);
    return 0;
}