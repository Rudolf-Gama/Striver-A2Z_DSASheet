#include<bits/stdc++.h>
#include<queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};
 
  Node* tree(int in[],int inS,int inE,int post[],int postS,int postE,map<int,int>& mpp){
        if(inS>inE || postS>postE) return NULL;
        
        Node* root=new Node(post[postE]);
        int inroot=mpp[root->data];
        int nleft=inroot-inS;
        
        root->left=tree(in,inS,inS+nleft-1,post,postS,postS+nleft-1,mpp);
        root->right=tree(in,inS+nleft+1,inE,post,postS+nleft,postE-1,mpp);
        return root;
    }
    Node *buildTree(int n, int in[], int post[]) {
        // Your code here
        map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[in[i]]=i;
        }
        
        Node* root=tree(in,0,n-1,post,0,n-1,mpp);
        return root;
    }
    vector<int> preorder(Node* root, vector<int>& ans) {
    if (!root) return ans;
    ans.push_back(root->data);
    preorder(root->left, ans);
    preorder(root->right, ans);
    return ans;
   }
   
    vector <int> preOrder(Node* root)
{
  vector<int> ans;
  return preorder(root,ans);
}

    int main(){
       int n=6;
       int in[] = {4, 2, 5, 1, 6,3};
       int post[] = {4, 5, 2, 6, 3,1};
       Node* root = buildTree(n, in, post);
       vector<int> ans=preOrder(root);
       for(auto it:ans){
        cout<<it<<" ";
      }
      return 0;
    }