#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* back;

    Node(int data1,Node* next1,Node* back1){
        data=data1;
        next=next1;
        back=back1;
    }
    Node(int data1){
        data=data1;
        next=nullptr;
        back=nullptr;
    }
};

Node* convertDLL(vector<int> arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node *temp=new Node(arr[i],nullptr,mover);
        mover->next=temp;
        mover=mover->next; 
    }
    return head;
}

void print(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

Node* reverseDLL(Node* head)
{    
    if(head==NULL || head->next==NULL) return head;
    Node* temp=head;
    stack<int> st;
    while(temp!=NULL){
        st.push(temp->data);
        temp=temp->next;
    }
     temp=head;
    while(temp!=NULL){
        temp->data=st.top();
        st.pop();
        temp=temp->next;
    }
    return head;
}


Node* reverseDLLOP(Node* head)
{   
    // Write your code here  
    if(head==NULL || head->next==NULL) return head;
    Node* temp=head;
    Node* last=NULL;
    while(temp!=NULL){
        last=temp->back;
        temp->back=temp->next;
        temp->next=last;
        temp=temp->back;
    }
    return last->back;
}

int main(){
    vector<int> arr{3,5,6,7};
    Node* head=convertDLL(arr);
    print(head);
    head=reverseDLLOP(head);
    print(head);
    return 0;
}