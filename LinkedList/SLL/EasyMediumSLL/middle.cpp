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

Node *findMiddle(Node *head) {
    // Write your code here
    Node* temp=head;
    int n=0;
    while(temp!=NULL){
        n++;
        temp=temp->next;
    }
    temp=head;
    int m=(n/2)+1;
    int cnt=0;
    while(temp!=nullptr){
        cnt++;
        if(cnt==m)
        break;
        temp=temp->next;
    }
    return temp;
}

Node *findMiddleOP(Node *head) {
    // Write your code here
    Node* slow=head;
    Node* fast=head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
int main(){
    vector<int> arr{3,5,6,7,8};
    Node* head=convertLL(arr);
    traversal(head);
    Node* middle=findMiddleOP(head);
    cout<<middle->data;
    return 0;
}