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
Node* deleteMid(Node* head)
    {
        // Your Code Here
        if(head==NULL || head->next==NULL) return NULL;
        Node* temp=head;
        int cnt=0;
        while(temp!=NULL){
            temp=temp->next;
            cnt++;
        }
        int m=cnt/2;
        temp=head;
        while(temp!=nullptr){
            m--;
            if(m==0){
                Node* mid=temp->next;
                temp->next=temp->next->next;
                free(mid);
            }
            temp=temp->next;
        }
        return head;
    }
 Node* deleteMidOP(Node* head)
    {
        // Your Code Here
        if(head==NULL || head->next==NULL) return nullptr;
        Node* slow=head;
        Node* fast=head;
        fast=fast->next->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        Node* mid=slow->next;
        slow->next=slow->next->next;
        free(mid);
        return head;
    }
Node* deleteMid(Node* head) {
    if (head == NULL || head->next == NULL) return NULL;
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;  

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    if (prev != NULL) {
        prev->next = slow->next;
    }
    delete slow;
    return head;
}
    int main(){
    vector<int> arr{3,5,6,8,9};
    Node* head=convertLL(arr);
    traversal(head);
    Node* middle=deleteMid(head);
    traversal(middle);
    return 0;
}