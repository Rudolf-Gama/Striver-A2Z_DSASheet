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

  Node* reverseList(Node* temp){
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
    Node *reverse(Node *head, int k)
    {
        // code here
        if(head==NULL) return NULL;
        
        Node* first=head;
        while(k>1){
            first=first->next;
            k--;
        }
        Node* sec=first->next;
        first->next=NULL;
        Node* newHead=reverseList(head);
        Node * newhead2=reverseList(sec);
        head->next=newhead2;
        return newHead;
    }
int main(){
    vector<int> arr{1,2,3,5,6,7,8};
    int k;
    cin>>k;
    Node* head=convertLL(arr);
    traversal(head);
    head=reverse(head,k);
    traversal(head);
    return 0;
}