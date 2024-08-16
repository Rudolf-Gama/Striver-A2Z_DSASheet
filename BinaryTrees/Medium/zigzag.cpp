#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector <int> zigZagTraversal(Node* root)
    {	// Code here
        queue<Node*> q;
        vector<int> ans;
        q.push(root);
        bool flag=true;
        while(!q.empty()){
            int s=q.size();
            vector<int> level;
            for(int i=0;i<s;i++){
                Node* temp=q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                level.push_back(temp->data);
            }
            if(!flag) reverse(level.begin(),level.end());
               flag=!flag;
            for(auto it: level){
                ans.push_back(it);
            }
        }
      return ans;
    }


int main(){
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(60);
    
    vector<int> ans=zigZagTraversal(root);
    for(auto it: ans){
        cout<<it<<" ";
    }
    return 0;
}