/*
Given a singly linked list of size N. The task is to left-shift the linked list by k nodes, where k is a given positive integer smaller than or equal to length of the linked list.

Example 1:

Input:
N = 5
value[] = {2, 4, 7, 8, 9}
k = 3
Output: 8 9 2 4 7
Explanation:
Rotate 1: 4 -> 7 -> 8 -> 9 -> 2
Rotate 2: 7 -> 8 -> 9 -> 2 -> 4
Rotate 3: 8 -> 9 -> 2 -> 4 -> 7

move one linked list to the left  (left shift) (<<)  (x*2^k)
*/
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
        mover=mover->next; 
    }
    return head;
}

void traversal(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}


 Node* rotate(Node* head, int k)
    {
        // Your code here
    if(head==NULL || k==0){
          return head;
     }
     Node* tail=head;
     while(tail->next!=NULL){
          tail=tail->next;
     }
     tail->next=head;
     Node* temp=head;
     for(int i=1;i<k;i++){
          temp=temp->next;
     }
     head=temp->next;
     temp->next=NULL;
     return head;
    }

 int main(){
    vector<int> arr{3,5,6,8,9,10};
    int k;
    cin>>k;
    Node* head=convertLL(arr);
    traversal(head);
    head=rotate(head,k);
    traversal(head);
    return 0;
}