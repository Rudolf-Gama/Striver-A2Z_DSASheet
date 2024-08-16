#include<bits/stdc++.h>
using namespace std;

struct Tree{
    int data;
    Tree* left;
    Tree* right;
    
    Tree():data(0),left(nullptr),right(nullptr){
    }
    Tree(int val):data(val),left(nullptr),right(nullptr){
    }
};

void create_tree(Tree* root0, vector<int> &vec){
           root0->left= new Tree(vec[1]);
           root0->right=new Tree(vec[2]);
           
           root0->left->left=new Tree(vec[3]);
           root0->left->right=new Tree(vec[4]);
           
           root0->right->left=new Tree(vec[5]);
           root0->right->right=new Tree(vec[6]);
    }

int main(){
     Tree* root = new Tree(1);
     vector<int> arr{2,4,5,6,7,8};
     create_tree(root,arr);
     return 0;
}