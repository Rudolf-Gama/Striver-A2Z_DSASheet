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

Node *sortLLBP(Node *head)
{
    // Write your code here.
	Node* temp=head;
	vector<int> arr;
	while(temp!=NULL){
        arr.push_back(temp->data);
		temp=temp->next;
	}
	sort(arr.begin(),arr.end());
	int i=0;
	temp=head;
	while(temp!=NULL){
		temp->data=arr[i];
		i++;
		temp=temp->next;
	}
	return head;
}
Node* findmid(Node* head){
	Node* slow=head;
	Node* fast=head->next;
	while(fast!=NULL && fast->next!=NULL){
		fast=fast->next->next;
		slow=slow->next;
	}
	return slow;
}

Node* merge(Node* list1,Node* list2){
	Node* dummy=new Node(-1);
	Node* temp=dummy;
	while(list1!=NULL && list2!=NULL){
		if(list1->data<list2->data){
			temp->next=list1;
			temp=list1;
			list1=list1->next;
		}
		else{
			temp->next=list2;
			temp=list2;
			list2=list2->next;
		}
	}
	if(list1) temp->next=list1;
	else temp->next=list2;

	return dummy->next;
}
Node *sortLL(Node *head)
{
    // Write your code here.
    if(head==NULL || head->next==NULL){
	return head;
    }
	Node* mid=findmid(head);
	Node* lefthead=head;
	Node* righthead=mid->next;
	mid->next=NULL;

	lefthead=sortLL(lefthead);
	righthead=sortLL(righthead);

	return merge(lefthead,righthead);
}

    int main(){
    vector<int> arr{1,2,2,0,0,2,1,0};
    Node* head=convertLL(arr);
    traversal(head);
    Node* middle=sortLL(head);
    traversal(middle);
    return 0;
}