#include<bits/stdc++.h>
#include<queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

void inorder(Node* root,int target,Node* &tar){
        if(root==NULL) return ;
        inorder(root->left,target,tar);
        if(root->data==target){
            tar=root; 
        }
        inorder(root->right,target,tar);
    }
    void markparent(Node* root,unordered_map<Node*,Node*> &mpp){
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* temp=q.front();
            q.pop();
            if(temp->left){
                mpp[temp->left]=temp;
                q.push(temp->left);
            }
            if(temp->right){
                mpp[temp->right]=temp;
                q.push(temp->right);
            }
        }
    }
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // return the sorted vector of all nodes at k dist
        Node* tar=NULL;
        inorder(root,target,tar);
        unordered_map<Node*,Node*>mpp;
        markparent(root,mpp);
        unordered_map<Node*,bool> visited;
        queue<Node*> q;
        q.push(tar);
        visited[tar]=true;
        int cnt=0;
        while(!q.empty()){
            int s=q.size();
            if(cnt++==k) break;
           for(int i=0;i<s;i++){
            Node* temp=q.front();
            q.pop();
            if(temp->left && !visited[temp->left]){
                q.push(temp->left);
                visited[temp->left]=true;
            }
            if(temp->right && !visited[temp->right]){
                q.push(temp->right);
                visited[temp->right]=true;
            }
            if(mpp[temp] && !visited[mpp[temp]]){
                q.push(mpp[temp]);
                visited[mpp[temp]]=true;
            }
          }
        }
        vector<int> ans;
        while(!q.empty()){
            Node* temp=q.front();
            q.pop();
            ans.push_back(temp->data);
        }
         sort(ans.begin(),ans.end());
         return ans;
    }




void markparentOP(Node* root,Node * &res,int target,unordered_map<Node*,Node*> &mpp){
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* temp=q.front();
            q.pop();
            if(temp->data==target) res=temp;
            if(temp->left){
                mpp[temp->left]=temp;
                q.push(temp->left);
            }
            if(temp->right){
                mpp[temp->right]=temp;
                q.push(temp->right);
            }
        }
    }

    vector <int> KDistanceNodesOP(Node* root, int target , int k)
    {
        // return the sorted vector of all nodes at k dist
        Node* tar=NULL;
        unordered_map<Node*,Node*>mpp;
        markparentOP(root,tar,target,mpp);
        unordered_map<Node*,bool> visited;
        queue<Node*> q;
        q.push(tar);
        visited[tar]=true;
        int cnt=0;
        while(!q.empty()){
            int s=q.size();
            if(cnt++==k) break;
           for(int i=0;i<s;i++){
            Node* temp=q.front();
            q.pop();
            if(temp->left && !visited[temp->left]){
                q.push(temp->left);
                visited[temp->left]=true;
            }
            if(temp->right && !visited[temp->right]){
                q.push(temp->right);
                visited[temp->right]=true;
            }
            if(mpp[temp] && !visited[mpp[temp]]){
                q.push(mpp[temp]);
                visited[mpp[temp]]=true;
            }
          }
        }
        vector<int> ans;
        while(!q.empty()){
            Node* temp=q.front();
            q.pop();
            ans.push_back(temp->data);
        }
         sort(ans.begin(),ans.end());
         return ans;
    }


    
 int main(){
    Node* root = new Node(15);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(25);
    root->left->right = new Node(35);
    vector<int>ans=KDistanceNodes(root,root->left->data,1);
    for(auto it: ans){
        cout<<it<<" ";
    }
    return 0;
}