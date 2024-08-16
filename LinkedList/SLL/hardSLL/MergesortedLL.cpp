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

Node* sortedMerge(Node* head1, Node* head2)  
{  
    // code here
    Node* dummy=new Node(-1);
    Node* temp=dummy;
    Node* temp1=head1;
    Node* temp2=head2;
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->data<temp2->data){
            temp->next=temp1;
            temp=temp1;
            temp1=temp->next;
        }
        else{
            temp->next=temp2;
            temp=temp2;
            temp2=temp2->next;
        }
    }
    if(temp1) temp->next=temp1;
    else temp->next=temp2;

    return (dummy->next);
}  


 int main(){
    vector<int> arr{3,5,6,8,9,10};
    vector<int> arr1{1,2,4,6,7,15};
    Node* head1=convertLL(arr);
    Node* head2=convertLL(arr1);
    traversal(head1);
    traversal(head2);
    Node* head=sortedMerge(head1,head2);
    traversal(head);
    return 0;
}