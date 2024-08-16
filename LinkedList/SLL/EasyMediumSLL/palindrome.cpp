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

bool isPalindrome(Node *head)
{
    stack<int> st;
    Node* temp=head;
    while(temp!=NULL){
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp!=nullptr){
        if(temp->data!=st.top()){
            return false;
        }
        st.pop();
        temp=temp->next;
    }
    return true;  
}

Node* reverse(Node* head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    Node*prev=nullptr;
    Node*front=nullptr;
    Node* temp=head;
    while(temp!=nullptr){
      front=temp->next;
      temp->next=prev;
      prev=temp;
      temp=front; 
    } 
    return prev;
}

bool isPalindromeOP(Node *head)
{
   Node* fast=head;
   Node* slow=head;
   while(fast->next!=nullptr && fast->next->next!=nullptr){
       fast=fast->next->next;
       slow=slow->next;
   }
   Node* newhead=reverse(slow->next);
   Node* first=head;
   Node* second=newhead;
   while(second!=nullptr){
       if(first->data!=second->data){
            Node* orghead=reverse(newhead);
            return false;
       }
       first=first->next;
       second=second->next;
   }
      Node* orghead=reverse(newhead);
   return true;  
}

int main(){
    vector<int> arr{3,1,2,1,3};
    Node* head=convertLL(arr);
    traversal(head);
    cout<<isPalindromeOP(head);
    return 0;
}