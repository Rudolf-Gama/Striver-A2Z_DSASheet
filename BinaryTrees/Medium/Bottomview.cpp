#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> ans;
        queue<pair<Node*,int>> q;
        map<int,int> mpp;
        q.push({root,0});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            Node* node=it.first;
            int line=it.second;
            mpp[line]=node->data;
            if(node->left!=NULL) q.push({node->left,line-1});
            if(node->right!=NULL) q.push({node->right,line+1});
        }
        for(auto it: mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
int main(){
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(60);
    
    vector<int> ans=bottomView(root);
    for(auto it: ans){
        cout<<it<<" ";
    }
    return 0;
}

