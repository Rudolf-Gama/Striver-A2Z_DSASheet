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

Node* reverse(Node* temp){
    Node* prev=NULL;
    Node* front=NULL;
    while(temp!=NULL){
        front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}
Node* findknode(Node* temp,int k){
    k--;
    while(temp!=NULL && k>0){
        temp=temp->next;
        k--;
    }
    return temp;
}
Node* kReverse(Node* head, int k) {
    // Write your code here.
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL){
        Node* knode=findknode(temp,k);
        if(!knode){
            if(prev) prev->next=temp;
            break;
        }
        Node* nextNode=knode->next;
        knode->next=nullptr;
        Node* newHead= reverse(temp);
        if(temp==head){
            head=newHead;
        }
        else{
            prev->next=newHead;
        }
        prev=temp;
        temp=nextNode;
    }
    return head;
}

/*
Given a linked list of size N. The task is to reverse every k nodes 
(where k is an input to the function) in the linked list. If the number
 of nodes is not a multiple of k then left-out nodes, in the end, should 
 be considered as a group and must be reversed (See Example 2 for clarification).

Input:
LinkedList: 1->2->3->4->5
K = 3
Output: 3 2 1 5 4 
Explanation: 
The first 3 elements are 1,2,3 are reversed 
first and then elements 4,5 are reversed.Hence, 
the resultant linked list is 3->2->1->5->4.
*/
Node* kReversemod(Node* head, int k) {
    // Write your code here.
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL){
        Node* knode=findknode(temp,k);
        if(!knode){
            Node* newHead=reverse(temp);
            if(prev) prev->next=newHead;
            break;
        }
        Node* nextNode=knode->next;
        knode->next=nullptr;
        Node* newHead= reverse(temp);
        if(temp==head){
            head=newHead;
        }
        else{
            prev->next=newHead;
        }
        prev=temp;
        temp=nextNode;
    }
    return head;
}


 int main(){
    vector<int> arr{3,5,6,8,9,10};
    int k;
    cin>>k;
    Node* head=convertLL(arr);
    traversal(head);
    head=kReversemod(head,k);
    traversal(head);
    return 0;
}
