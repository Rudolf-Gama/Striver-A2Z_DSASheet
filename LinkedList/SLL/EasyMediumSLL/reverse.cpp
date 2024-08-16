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

Node* reverseLinkedList(Node *head)
{
    // Write your code here
    Node*temp=head;
    stack<int> st;
    while(temp!=nullptr){
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp!=nullptr){
        temp->data=st.top();
        st.pop();
        temp=temp->next;
    }
    return head;
}
Node* reverseLinkedListIT(Node *head)
{
    // Write your code here
    Node*temp=head;
    Node* front=nullptr;
    Node*prev=nullptr;
    while(temp!=nullptr){
        front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }   
    return prev;
}
Node* reverseLinkedListRE(Node *head)
{
    // Write your code here
   if(head==NULL || head->next==NULL){
       return head;
   }
   Node* newhead=reverseLinkedListRE(head->next);
   Node* front=head->next;
   head->next=nullptr;
   front->next=head;
   return newhead;
}

int main(){
    vector<int> arr{3,5,6,7,8};
    Node* head=convertLL(arr);
    traversal(head);
    head=reverseLinkedListRE(head);
    traversal(head);
    return 0;
}