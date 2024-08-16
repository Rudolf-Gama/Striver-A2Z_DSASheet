#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
vector<int> topView(Node *root)
    {
        //Your code here
        vector<int>ans;
        if(root==NULL) return ans;
        map<int,int> mpp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            Node* temp=it.first;
            int line=it.second;
            if(mpp.find(line)==mpp.end()) mpp[line]=temp->data;
            if(temp->left) q.push({temp->left,line-1});
            if(temp->right) q.push({temp->right,line+1});
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
    
    vector<int> ans=topView(root);
    for(auto it: ans){
        cout<<it<<" ";
    }
    return 0;
}