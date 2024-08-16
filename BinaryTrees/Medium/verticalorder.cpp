#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<int> verticalOrder(Node *root)
    {
        //Your code here
        queue<pair<Node*,pair<int,int>>> q;
        map<int,map<int,vector<int>>> mpp;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto p= q.front();
            q.pop();
            Node* node=p.first;
            int h=p.second.first;
            int lvl=p.second.second;
            mpp[h][lvl].push_back(node->data);
            if(node->left) q.push({node->left,{h-1,lvl+1}});
            if(node->right) q.push({node->right,{h+1,lvl+1}});
        }
        vector<vector<int>>ans;
        for(auto it: mpp){
            vector<int>col;
            for(auto q: it.second ){
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        vector<int>adj;
        for(auto it: ans){
            for(int i : it){
                adj.push_back(i);
            }
        }
        return adj;
    }

int main(){
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(60);
    
    vector<int> ans=verticalOrder(root);
    for(auto it: ans){
        cout<<it<<" ";
    }
    return 0;
}