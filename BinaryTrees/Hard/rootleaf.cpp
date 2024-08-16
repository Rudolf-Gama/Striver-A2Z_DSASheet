#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
bool helper(Node * root,vector<int> &arr,vector<vector<int>> &ans){
        if(root==NULL) return false;
        arr.push_back(root->data);
        if(!root->left && !root->right) {
            ans.push_back(arr);
            arr.pop_back();
            return true;
        }
        helper(root->left,arr,ans);
        helper(root->right,arr,ans);
        arr.pop_back();
        return true;
    }
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        vector<int> arr;
        helper(root,arr,ans);
        return ans;
    }

    int main(){
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(15);
    root->left->left = new Node(30);
    root->right->right = new Node(40);
    vector<vector<int>> res=Paths(root);
    for(auto it : res){
        for(auto i : it){
            cout<<i<<" ";
        }
        cout<< endl;
    }
    return 0;
}