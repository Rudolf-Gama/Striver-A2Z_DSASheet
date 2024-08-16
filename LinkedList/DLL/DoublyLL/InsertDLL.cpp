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

Node* InssertBHead(Node* head,int val){
    Node*temp=new Node(val,head,nullptr);
    head->back=temp;
    return temp;
}
Node* InssertAHead(Node* head,int val){
    Node* front=head->next;
    Node* temp=new Node(val,front,head);
    head->next=temp;
    front->back=temp;
    return head;
}

Node* InsertBTail(Node* head,int val){
    if(head->next==NULL){
        return InssertBHead(head,val);
    }
    Node* tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    Node* prev=tail->back;
    Node* newNode=new Node(val,tail,prev);
    tail->back=newNode;
    prev->next=newNode;
    return head;
}

Node* InsertATail(Node* head,int val){
    if(head==NULL){
        return new Node(val);
    }
    if(head->next==NULL){
        return InssertAHead(head,val);
    }
    Node* tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    Node* newNode=new Node(val,nullptr,tail);
    tail->next=newNode;
    return head;
}
Node* InsertKposition(Node* head,int val,int k){
    if(k==1){
        return InssertBHead(head,val);
    }
    Node* temp=head;
    int cnt=0;
    while(temp!=nullptr){
        cnt++;
        if(cnt==k){
            break;
        }
        temp=temp->next;
    }
    if(cnt<k) return head;
    Node* prev=temp->back;
    Node* newNode=new Node(val,temp,prev);
    prev->next=newNode;
    temp->back=newNode;
    return head;
}

void InsertBvalue(Node* node,int val){
    Node* prev=node->back;
    Node* newNode=new Node(val,node,prev);
    prev->next=newNode;
    node->back=newNode;
}

int main(){
    vector<int> arr{3,5,6,7};
    Node* head=convertDLL(arr);
    print(head);
    // head=InssertAHead(head,10);
    // head=InsertBTail(head,10);
    head=InsertATail(head,10);
    //   head=InsertKposition(head,100,3);
    // InsertBvalue(head->next,100);
    print(head);
    return 0;
}