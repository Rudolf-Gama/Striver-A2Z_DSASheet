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

int searching(Node* head,int value){
    Node* temp=head;
    while(temp){
        if(temp->data==value)
         return 1;
         temp=temp->next;
    }
    return 0;
}

int lengthofLL(Node* head){
    Node* temp=head;
    int cnt=0;
    while(temp){
        cnt++;
         temp=temp->next;
    }
    return cnt;
}

int main(){
    vector<int> arr{3,5,6,7,8,9};
    Node* head=convertLL(arr);
    cout<<searching(head,8)<<endl;
    cout<<lengthofLL(head);
    return 0;
}