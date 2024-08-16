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
        mover=mover->next; //mover=temp;
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

Node* InsertHead(Node* head,int val){
    return new Node(val,head);
}

Node* InsertTail(Node* head,int val){
    Node* newNode=new Node(val);
    Node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    return head;
}

Node* InsertPosition(Node* head,int val,int k){
    if(head==NULL){
        if(k==1){
            return new Node(val);
        }
        else {
            return head;
        }
    }
    if(k==1){
        return new Node(val,head);
    }
    int cnt=0;
    Node* temp=head;
    while(temp!=NULL){
        cnt++;
        if(cnt==k-1){
            Node* newNode=new Node(val,temp->next);
            temp->next=newNode;
            break;
        }
        temp=temp->next;
    }
    return head;
}


Node* InsertPositionru(Node* head,int val,int k){
    if(head==NULL){
        if(k==1){
            return new Node(val);
        }
        else {
            return head;
        }
    }
    if(k==1){
        return new Node(val,head);
    }
    int cnt=0;
    Node* temp=head;
    while(temp->next!=NULL){
        cnt++;
        if(cnt==k-1){
            Node* newNode=new Node(val,temp->next);
            temp->next=newNode;
            return head;
        }
        temp=temp->next;
    }
    cnt++;
    if(cnt==k-1){
    Node* newNode=new Node(val,temp->next);
    temp->next=newNode;
    }
    return head;
}

Node* Insertvalue(Node* head,int value,int ele){
    if(head==NULL){
          return NULL;
    }
    if(head->data==ele){
        return new Node(value,head);
    }
    Node* temp=head;
    while(temp->next!=NULL){
        if(temp->next->data==ele){
            Node* newNode=new Node(value,temp->next);
            temp->next=newNode;
            break;
        }
        temp=temp->next;
    }
    return head;
}

int main(){
    vector<int> arr{3,5,6,7,8,9};
    Node* head=convertLL(arr);
    print(head);
    // head=InsertHead(head,100);
    // head=new Node(100,head);

    // head=InsertTail(head,200);

    // head=InsertPosition(head,300,8);

    head=Insertvalue(head,10,0);
    print(head);
    return 0;
}