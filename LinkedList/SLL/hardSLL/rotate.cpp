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


Node *rotate(Node *head, int k) {
     // Write your code here.
     if(head==NULL || k==0){
          return head;
     }
     Node* tail=head;
     int len=1;
     while(tail->next!=NULL){
          tail=tail->next;
          len++;
     }
     if(k%len==0) return head;
     k=k%len;
     tail->next=head;
     Node* temp=head;
     for(int i=1;i<(len-k);i++){
          temp=temp->next;
     }
     head=temp->next;
     temp->next=NULL;
     return head;
}

 int main(){
    vector<int> arr{3,5,6,8,9,10};
    int k;
    cin>>k;
    Node* head=convertLL(arr);
    traversal(head);
    head=rotate(head,k);
    traversal(head);
    return 0;
}