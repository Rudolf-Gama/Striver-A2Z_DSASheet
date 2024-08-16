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

Node* convertLL(vector<int> arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node *temp=new Node(arr[i]);
        mover->next=temp;
        mover=mover->next; //mover=temp;
    }
    return head;
}

void traversal(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" "<<temp->next<<endl;
        temp=temp->next;
    }
}

int main(){
    vector<int> arr{3,5,6,7};
    Node* head=convertLL(arr);
    traversal(head);
    return 0;
}