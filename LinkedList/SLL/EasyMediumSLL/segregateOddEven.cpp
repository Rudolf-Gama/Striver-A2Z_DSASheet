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
Node* oddEvenList(Node* head)
{
	// Write your code here.
    vector<int> ans;
    Node* temp=head;
    while(temp!=nullptr&& temp->next!=nullptr)
    {
        ans.push_back(temp->data);
        temp=temp->next->next;
    }
    if(temp) ans.push_back(temp->data);
    temp=head->next;
    while(temp!=nullptr&& temp->next!=nullptr)
    {
        ans.push_back(temp->data);
        temp=temp->next->next;
    }
    if(temp) ans.push_back(temp->data);
    int i=0;
    temp=head;
    while(temp!=nullptr){
        temp->data=ans[i];
        i++;
        temp=temp->next;
    }
    return head;
}

Node* oddEvenList(Node* head)
{
	// Write your code here.
    if(head==nullptr || head->next==nullptr) return head;
    Node* odd=head;
    Node* even=head->next;
    Node* evenhead=even;
    while(even!=nullptr && even->next!=nullptr){
        odd->next=odd->next->next;
        even->next=even->next->next;

        odd=odd->next;
        even=even->next;
    }
    odd->next=evenhead;
    return head;
}


int main(){
    vector<int> arr{3,1,2,5,7,8,9};
    Node* head=convertLL(arr);
    traversal(head);
    head=oddEvenList(head);
    traversal(head);
    return 0;
}