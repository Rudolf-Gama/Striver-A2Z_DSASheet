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

Node* DeleHead(Node* head){
    if(head==NULL) return head;
    Node* temp=head;
    head=head->next;
    free(temp);
    return head;
}

Node* DeleTail(Node* head){
    if(head==NULL || head->next==NULL) return NULL;
    Node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=nullptr;
    return head;
}
Node* DelePositionMe(Node* head,int k){
    if(head==NULL) return head;
    if(k==1){
    Node* temp=head;
    head=head->next;
    free(temp);
    return head;  
    }

    int cnt=0;
    Node* prev=NULL;
    Node* temp=head;
    while(temp->next!=NULL){
        cnt++;
        if(cnt==k){
            prev->next=prev->next->next;
            free(temp);
            return head;
        }
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    free(temp);
    return head;
}

Node* DelePosition(Node* head,int k){
    if(head==NULL) return head;
    if(k==1){
    Node* temp=head;
    head=head->next;
    free(temp);
    return head;  
    }

    int cnt=0;
    Node* prev=NULL;
    Node* temp=head;
    while(temp!=NULL){
        cnt++;
        if(cnt==k){
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}
Node* DeleElement(Node* head,int ele){
    if(head==NULL) return head;
    if(ele==head->data){
    Node* temp=head;
    head=head->next;
    free(temp);
    return head;  
    }

    Node* prev=NULL;
    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==ele){
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}


int main(){
    vector<int> arr{3,5,6,7,8,9};
    Node* head=convertLL(arr);
    print(head);
    //head=DeleHead(head);
    // head=DeleTail(head);
    // head=DelePosition(head,3);
    head=DeleElement(head,10);
    print(head);
    return 0;
}