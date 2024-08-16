#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
bool isleaf(Node* root){
        return !root->left && !root->right;
    }
    void addleft(Node* root,vector<int> &ans){
        Node* cur=root->left;
        while(cur){
            if(!isleaf(cur)) ans.push_back(cur->data);
            if(cur->left) cur=cur->left;
            else cur=cur->right;
        }
    }
    void addright(Node* root,vector<int> &ans){
        Node* cur=root->right;
        vector<int> temp;
        while(cur){
            if(!isleaf(cur)) temp.push_back(cur->data);
            if(cur->right) cur=cur->right;
            else cur=cur->left;
        }
        int n=temp.size();
        for(int i=n-1;i>=0;i--){
            ans.push_back(temp[i]);
        }
    }
    void addleaf(Node* root,vector<int>& ans){
        if(isleaf(root)){
             ans.push_back(root->data);
             return;
        }
        if(root->left) addleaf(root->left,ans);
        if(root->right) addleaf(root->right,ans);
    }
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> ans;
        if(!root) return ans;
        if(!isleaf(root)) ans.push_back(root->data);
        addleft(root,ans);
        addleaf(root,ans);
        addright(root,ans);
        return ans;
    }

    
int main(){
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(60);
    
    vector<int> ans=boundary(root);
    for(auto it: ans){
        cout<<it<<" ";
    }
    return 0;
}