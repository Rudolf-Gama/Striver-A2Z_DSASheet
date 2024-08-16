#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void view(Node* root,vector<int>&ans,int lvl){
    if(root==NULL) return ;
    if(lvl==ans.size()) ans.push_back(root->data);
    view(root->left,ans,lvl+1);
    view(root->right,ans,lvl+1);
}
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> ans;
   view(root,ans,0);
   return ans;
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(60);
    vector<int> ans=leftView(root);
    for(auto it: ans){
        cout<<it<<" ";
    }
    return 0;
}