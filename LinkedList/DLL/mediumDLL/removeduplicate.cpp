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

 Node * removeDuplicatesMy(struct Node *head)
    {
        // Your code here
        Node* temp=head;
        while(temp->next!=NULL){
            if(temp->data==temp->next->data){
                Node* del=temp->next;
                Node* front=temp->next->next;
                temp->next=front;
                if(front) front->prev=temp;
                free(del);
            }
            else{
                temp=temp->next;
            }
        }
        return head;
    }

    Node * removeDuplicates(Node *head)
{
    // Write your code here
    Node* temp=head;
    while(temp!=NULL && temp->next!=NULL){
        Node* nextnode=temp->next;
        while(nextnode!=NULL && temp->data==nextnode->data){
            Node * del=nextnode;
            nextnode=nextnode->next;
            delete del;
        }
        temp->next=nextnode;
        if(nextnode) nextnode->prev=temp;
        temp=temp->next;
    }
    return head;
}
int main(){
    vector<int> arr{3,6,6,7,8,8,8,9};
    Node* head=convertDLL(arr);
    print(head);
    head=removeDuplicates(head);
    print(head);
    return 0;
}