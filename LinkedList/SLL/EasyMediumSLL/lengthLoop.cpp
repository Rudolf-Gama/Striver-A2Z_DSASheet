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

int countNodesinLoop(Node *head) {
    // Write your code here
    map<Node*,int>mpp;
    Node*temp=head;
    int timer=1;
    while(temp!=nullptr){
      if (mpp.find(temp) != mpp.end()) {
          int value=mpp[temp];
            return {timer-value};
        }
        mpp[temp]=timer;
        timer++;
        temp=temp->next;
    }
    return 0;
}
int length(Node* slow,Node* fast){
    int cnt=1;
    slow=slow->next;
    while(slow!=fast){
        cnt++;
        slow=slow->next;
    }
    return cnt;
}

int countNodesinLoopOP(struct Node *head)
{
    // Code here
    Node* slow=head;
    Node* fast=head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) return length(slow,fast) ;
    }
    return 0;
}

int main(){
    vector<int> arr{3,5,6,7,8};
    Node* head=convertLL(arr);
    // traversal(head);
    cout<<countNodesinLoop(head);
    return 0;
}