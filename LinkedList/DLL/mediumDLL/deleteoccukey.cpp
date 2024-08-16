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

Node * deleteAllOccurrences(Node* head, int k) {
    // Write your code here
    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==k){
            if(temp==head){
                head=head->next;
            }
            Node* prevnode=temp->prev;
            Node* nextNode=temp->next;
            if(prevnode) prevnode->next=nextNode;
            if(nextNode) nextNode->prev=prevnode;
            free(temp);
            temp=nextNode;
        }
        else{
            temp=temp->next;
        }
    }
    return head;
}

int main(){
    vector<int> arr{3,6,6,7,5,6,7,7,7,3};
    int k;
    cin>>k;
    Node* head=convertDLL(arr);
    print(head);
    head=deleteAllOccurrences(head,k);
    print(head);
    return 0;
}