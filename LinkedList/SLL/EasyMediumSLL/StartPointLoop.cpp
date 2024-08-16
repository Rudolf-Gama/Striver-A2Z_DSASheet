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
    mover->next=head->next;
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

Node *firstNode(Node *head)
{
    map<Node*,int>mpp;
    Node*temp=head;
    while(temp!=nullptr){
        if(mpp.find(temp)!=mpp.end()){
            return temp;
        }
        mpp[temp]++;
        temp=temp->next;
    }
    return nullptr;
}

Node *firstNodeOP(Node *head)
{
    //    Write your code here.
    Node* slow=head;
    Node* fast=head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            slow=head;
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }
            return fast;
        };
    }
    return nullptr;
}

int main(){
    vector<int> arr{3,5,6,7,8};
    Node* head=convertLL(arr);
    // traversal(head);
    Node* start=firstNodeOP(head);
    cout<<start->data<<" "<<start->next;
    return 0;
}