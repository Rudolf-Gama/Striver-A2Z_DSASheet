#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<int> PreOrder(Node* root)
    {
        //code here
       vector<int> ans;
       Node* cur=root;
       while(cur!=NULL){
           if(cur->left==NULL){
               ans.push_back(cur->data);
               cur=cur->right;
           }
           else {
               Node* prev=cur->left;
               while(prev->right && prev->right!=cur){
                   prev=prev->right;
               }
               if(prev->right==NULL){
                   prev->right=cur;
                   ans.push_back(cur->data);
                   cur=cur->left;
               }
               else{
                   prev->right=NULL;
                   cur=cur->right;
               }
           }
       }
       return ans;
    }

   int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> result = PreOrder(root);

    cout << "Preorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}