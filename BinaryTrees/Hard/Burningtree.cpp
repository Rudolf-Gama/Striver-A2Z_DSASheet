#include<bits/stdc++.h>
#include<queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};


void makeparent(Node* root,Node* &res,int target,unordered_map<Node*,Node*>&mpp){
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* temp=q.front();
            q.pop();
            if(temp->data==target) res=temp;
            if(temp->left) {
                mpp[temp->left]=temp;
                q.push(temp->left);
            }
            if(temp->right){
                mpp[temp->right]=temp;
                q.push(temp->right);
            }
        }
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        Node* tar=NULL;
        unordered_map<Node*,Node*>mpp;
        makeparent(root,tar,target,mpp);
        unordered_map<Node*,bool> visit;
        queue<Node*> q;
        q.push(tar);
        visit[tar]=true;
        int cnt=-1;
        while(!q.empty()){
            int s=q.size();
            cnt++;
            for(int i=0;i<s;i++){
                Node* temp=q.front();
                q.pop();
                if(temp->left && !visit[temp->left]){
                    visit[temp->left]=true;
                    q.push(temp->left);
                }
                if(temp->right && !visit[temp->right]){
                    visit[temp->right]=true;
                    q.push(temp->right);
                }
                if(mpp[temp] && !visit[mpp[temp]]){
                     visit[mpp[temp]]=true;
                    q.push(mpp[temp]);
                }
            }
        }
       return cnt; 
    }

     int main(){
    Node* root = new Node(15);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(25);
    root->left->right = new Node(35);
    cout<<minTime(root,10);
    return 0;
}