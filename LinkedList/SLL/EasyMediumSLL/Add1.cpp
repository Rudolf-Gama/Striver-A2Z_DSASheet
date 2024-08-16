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
        if(temp==NULL || temp->next==NULL) return temp;
        Node* front=NULL;
        Node* prev=NULL;
        while(temp!=NULL){
            front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        if(head==NULL) return NULL;
        Node* tail=reverse(head);
        int carry=1;
        Node* temp=tail;
        while(temp!=NULL){
          temp->data=temp->data+carry;
          if(temp->data<10) {
              carry=0;
              break;
          }
          else{
              carry=1;
              temp->data=0;
          }
          temp=temp->next;
        }
        if(carry==1){
            Node * newnode=new Node(1);
            head=reverse(tail);
            newnode->next=head;
             return newnode;
        }
       return reverse(tail); 
    }

     int helper(Node* head){
        if(head==NULL) return 1;
        int c=helper(head->next);
        head->data=head->data+c;
        if(head->data<10) 
            return 0;
        else 
        {   head->data=0;
             return 1;
        }
    }
    Node* addOneOP(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        int carry=helper(head);
        if(carry){
            Node* newnode=new Node(1);
            newnode->next=head;
            return newnode;
        }
        return head;
    }
    int main(){
    vector<int> arr{9,9,9,9,9};
    Node* head=convertLL(arr);
    traversal(head);
    head=addOneOP(head);
    traversal(head);
    return 0;
}