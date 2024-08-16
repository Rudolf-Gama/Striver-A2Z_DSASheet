 #include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

 Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here 
       if(root==NULL || root->data==n1 || root->data==n2){
           return root;
       }
       Node* l=lca(root->left,n1,n2);
       Node* r=lca(root->right,n1,n2);
       if(l==NULL) return r;
       else if(r==NULL) return l;
       else return root;
    }


    int main(){
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(15);
    root->left->left = new Node(30);
    root->right->right = new Node(40);
    cout<<lca(root,20,40)->data<<endl;
    return 0;
}