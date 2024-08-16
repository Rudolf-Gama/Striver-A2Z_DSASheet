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

int main(){
     Tree* root = new Tree(1);
    root->left = new Tree(2);
    root->right = new Tree(3);
    root->left->right = new Tree(5);
}