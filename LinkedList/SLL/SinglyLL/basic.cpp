#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;

    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};
int main(){
    // vector<int> arr{3,5,6,7};
    Node x=Node(8,nullptr);
    Node* y=&x;
    cout<<x.data<<" "<<x.next<<endl;

    Node *z=new Node(3);
    cout<<z->data<<" "<<z->next;
    return 0;
}