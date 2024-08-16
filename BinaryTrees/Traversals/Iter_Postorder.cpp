 #include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

 vector<int> postOrder(Node* node) {
        // code here
        vector<int> ans;
        stack<Node*> st;
        Node* cur=node;
        Node* temp=NULL;
        while(cur!=NULL || !st.empty()){
            if(cur!=NULL){
                st.push(cur);
                cur=cur->left;
            }
            else{
                temp=st.top()->right;
                if(temp==NULL){
                    temp=st.top();
                    st.pop();
                    ans.push_back(temp->data);
                    while(!st.empty() && temp==st.top()->right){
                        temp=st.top();
                        st.pop();
                        ans.push_back(temp->data);
                    }
                }
                else{
                    cur=temp;
                }
            }
        }
        return ans;
    }

    vector<int> postOrder2stack(Node* node) {
        // code here
        stack<Node*>st1;
        stack<Node*> st2;
        st1.push(node);
        vector<int> ans;
        while(!st1.empty()){
            node=st1.top();
            st1.pop();
            st2.push(node);
            if(node->left!=NULL) st1.push(node->left);
            if(node->right!=NULL) st1.push(node->right);
            }
        while(!st2.empty()){
            ans.push_back(st2.top()->data);
            st2.pop();
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
    
    vector<int> ans=postOrder(root);
    for(auto it: ans){
        cout<<it<<" ";
    }
    return 0;
}