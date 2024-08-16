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

Node* DeleHead(Node* head){
    if(head==NULL || head->next==NULL) return NULL;
    Node* prev=head;
    head=head->next;
    head->back=NULL;
    prev->next=NULL;
    return head;
}
Node* DelTail(Node* head){
    if(head==NULL || head->next==NULL) return NULL;
    Node* tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    Node* prev =tail->back;
    tail->back=NULL;
    prev->next=NULL;
    free(tail);
    return head;
}

Node* DelePosition(Node* head,int k){
    if(head==NULL)
    return NULL;
    int cnt=0;
    Node* temp=head;
    while(temp!=NULL){
        cnt++;
        if(cnt==k){
            break;
        }
        temp=temp->next;
    }
    if(cnt<k) return head;
    Node* prev=temp->back;
    Node* front=temp->next;
    if(prev==NULL && front==NULL)
    {
        return NULL;
    }
    else if(prev==NULL){
       return DeleHead(head);
    }
    else if(front==NULL){
       return  DelTail(head);
    }
        prev->next=front;
        front->back=prev;
        temp->next=NULL;
        temp->back=NULL;
        free(temp);
    return head;
}

void DelValue(Node* temp){
    Node*prev=temp->back;
    Node* front=temp->next;
    if(front==NULL){
        prev->next=nullptr;
        temp->back=nullptr;
        free(temp);
        return;
    }
        prev->next=front;
        front->back=prev;
        temp->next=NULL;
        temp->back=NULL;
        free(temp);
}

int main(){
    vector<int> arr{3,5,6,7};
    Node* head=convertDLL(arr);
    print(head);
    // head=DeleHead(head);
    // head=DelTail(head);
    // head=DelePosition(head,10);
    DelValue(head->next->next->next);
    print(head);
    return 0;
}