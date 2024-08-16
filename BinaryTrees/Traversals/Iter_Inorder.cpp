#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
vector<int> inOrder(Node* root)
    {
        //code here
        vector<int> ans;
        stack<Node*> st;
        Node* node=root;
        while(true){
            if(node!=NULL){
                st.push(node);
                node=node->left;
            }
            else{
                if(st.empty()) break;
                node=st.top();
                st.pop();
                ans.push_back(node->data);
                node=node->right;
            }
        }
        return ans;
    }
/*
Input:
           1
         /    \
       2       3
      /   \
    4     5
Output: 4 2 5 1 3
*/
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    
    vector<int> ans=inOrder(root);
    for(auto it: ans){
        cout<<it<<" ";
    }
    return 0;
}