#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<int> preOrder(Node* root)
    {
        //code here
        vector<int> ans;
        stack<Node*> st;
        st.push(root);
        while(!st.empty()){
            root=st.top();
            st.pop();
            ans.push_back(root->data);
            if(root->right!=NULL) st.push(root->right);
            if(root->left!=NULL) st.push(root->left);
        }
        return ans;
    }
/*
Input:
           1
         /   \
        2     3
      /  \
     4    5
Output: 1 2 4 5 3
*/

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    
    vector<int> ans=preOrder(root);
    for(auto it: ans){
        cout<<it<<" ";
    }
    return 0;
}