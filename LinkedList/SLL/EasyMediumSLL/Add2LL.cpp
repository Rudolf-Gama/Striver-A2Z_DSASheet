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

Node *addTwoNumbers(Node *num1, Node *num2)
{
    // Write your code here.
    Node* t1=num1;
    Node* t2=num2;
    int c=0;
    Node* dummy=new Node(-1);
    Node* cur=dummy;
    while(t1!=NULL || t2!=NULL){
        int sum=c;
        if(t1) sum+=t1->data;
        if(t2) sum+=t2->data;
        Node* newnode=new Node(sum%10);
        c=sum/10;
        cur->next=newnode;
        cur=newnode;

        if(t1) t1=t1->next;
        if(t2) t2=t2->next;
    }
    if(c){
        Node* newnode=new Node(c);
        cur->next=newnode;
    }
    return dummy->next;
}

 
    int main(){
    vector<int> arr{9,9,9,9};
    vector<int> arr2{1};
    Node* head1=convertLL(arr);
    Node* head2=convertLL(arr2);
    traversal(head1);
    traversal(head2);
    Node* newhead=addTwoNumbers(head1,head2);
    traversal(newhead);
    return 0;
}