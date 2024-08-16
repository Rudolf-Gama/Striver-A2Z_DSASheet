#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* prev;

    Node(int data1,Node* next1,Node* back1){
        data=data1;
        next=next1;
        prev=back1;
    }
    Node(int data1){
        data=data1;
        next=nullptr;
        prev=nullptr;
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
Node* sortedInsert(Node * head, int x)
{
	// Code here
     Node* newNode = new Node(x);
    
	if(head->data>x){
	   newNode->next=head;
	   head->prev=newNode;
	   return newNode;
	}
	
	Node* temp=head;
	while(temp->next!=NULL && temp->next->data<=x)
	{
	  temp=temp->next;
	}
	if(temp->next==NULL){
	    newNode->next=nullptr;
	    newNode->prev=temp;
	    temp->next=newNode;
	    return head;
	}
	else{
	Node* front=temp->next;
	newNode->next=front;
	newNode->prev=temp;
	temp->next=newNode;
	front->prev=newNode;
	return head;
	}
}

int main(){
    vector<int> arr{3,5,6,7};
    Node* head=convertDLL(arr);
    print(head);
    head=sortedInsert(head,8);
    print(head);
    return 0;
}