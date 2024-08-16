/*Given a linked list, you have to perform the following task:

Extract the alternative nodes starting from second node.
Reverse the extracted list.
Append the extracted list at the end of the original list.

LinkedList = 10->4->9->1->3->5->9->4
Output: 
10 9 3 9 4 5 1 4

*/
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

 Node* reverse(Node* head){
        if(head==NULL || head->next==NULL) return head;
        Node* front=NULL;
        Node* prev=NULL;
        Node* temp=head;
        while(temp!=NULL){
            front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
    void rearrange(struct Node *head)
    {
        //add code here
    Node* odd=head;
    Node* even=head->next;
    Node* evenhead=even;
    while(even!=nullptr && even->next!=nullptr){
        odd->next=odd->next->next;
        even->next=even->next->next;

        odd=odd->next;
        even=even->next;
    }
    Node* newhead=reverse(evenhead);
    odd->next=newhead;
    }
int main(){
    vector<int> arr{3,1,2,5,7,8,9};
    Node* head=convertLL(arr);
    traversal(head);
    rearrange(head);
    traversal(head);
    return 0;
}