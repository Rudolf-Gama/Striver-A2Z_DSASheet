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
Node *removeDuplicates(Node *head)
{
 // your code goes here
 if(head==NULL || head->next==NULL){
     return head;
 }
 Node* temp=head;
 Node* front=NULL;
 while(temp->next!=NULL){
     if(temp->data==temp->next->data){
        front=temp->next;
        temp->next=temp->next->next;
        free(front);
     }
     else
     temp=temp->next;
 }
 return head;
}

    int main(){
    vector<int> arr{3,3,5,6,6,8,9};
    Node* head=convertLL(arr);
    traversal(head);
    Node* middle=removeDuplicates(head);
    traversal(middle);
    return 0;
}