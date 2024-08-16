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

Node* removeKthNode(Node* head, int K)
{
    // Write your code here.
    Node* temp=head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        temp=temp->next;
    }
    if(cnt==K){
        Node* newhead=head->next;
        free(head);
        return newhead;
    }
    int res=cnt-K;
    temp=head;
    while(temp!=nullptr){
        res--;
        if(res==0) break;
        temp=temp->next;
    }
    Node* del=temp->next;
    temp->next=temp->next->next;
    free(del);
    return head;
}

    Node* removeKthNodeOP(Node* head, int K)
    {
        Node* fast=head;
        while(K>0){
            fast=fast->next;
            K--;
        }
        if(fast==NULL){
            Node* newhead=head->next;
            free(head);
            return newhead;
        }
        Node* slow=head;
        while(fast->next!=nullptr){
            fast=fast->next;
            slow=slow->next;
        }
        Node* del=slow->next;
        slow->next=slow->next->next;
        free(del);
        return head;
    }

int main(){
    vector<int> arr{3,1,2,1,3};
    Node* head=convertLL(arr);
    traversal(head);
    int K;
    cin>>K;
    head=removeKthNodeOP(head,K);
    traversal(head);
    return 0;
}