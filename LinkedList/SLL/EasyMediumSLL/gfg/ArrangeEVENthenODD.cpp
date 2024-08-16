/*Given a link list of size N, modify the list such that all the even numbers appear before all the odd numbers in the modified list. The order of appearance of numbers within each segregation should be same as that in the original list.
Link List:
17 -> 15 -> 8 -> 9 -> 2 -> 4 -> 6 -> NULL

Output: 8 2 4 6 17 15 9
*/
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


 Node* divide( Node *head){
        // code here
   if(head==NULL || head->next==NULL) return head;
    vector<int> even;
    vector<int> odd;
    Node* temp=head;
    while(temp!=nullptr)
    { 
        if(((temp->data)&1)==0)
        even.push_back(temp->data);
        else{
            odd.push_back(temp->data);
        }
        temp=temp->next;
    }
    if(even.size()==0) return head;
    temp=head;
    for(int i=0;i<even.size();i++){
        temp->data=even[i];
        temp=temp->next;
    }
    for(int i=0;i<odd.size();i++){
        temp->data=odd[i];
        temp=temp->next;
    }
    return head;
    }
    
int main(){
    vector<int> arr{3,1,2,5,7,8,9};
    Node* head=convertLL(arr);
    traversal(head);
    head=divide(head);
    traversal(head);
    return 0;
}