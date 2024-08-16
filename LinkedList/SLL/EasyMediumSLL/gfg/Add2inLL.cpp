/*
Given two numbers, num1 and num2, represented by linked lists of size n and m respectively. The task is to return a linked list that represents the sum of these two numbers.

For example, the number 190 will be represented by the linked list, 1->9->0->null, similarly 25 by 2->5->null. Sum of these two numbers is 190 + 25 = 215, which will be represented by 2->1->5->null. You are required to return the head of the linked list 2->1->5->null.

Note: There can be leading zeros in the input lists, but there should not be any leading zeros in the output list.

Example 1:

Input:
n = 2
num1 = 45 (4->5->null)
m = 3
num2 = 345 (3->4->5->null)
Output: 
3->9->0->null  
Explanation: 
For the given two linked list (4 5) and (3 4 5), after adding the two linked list resultant linked list will be (3 9 0).

Input:
n = 4
num1 = 0063 (0->0->6->3->null)
m = 2
num2 = 07 (0->7->null)
Output: 
7->0->null
Explanation: 
For the given two linked list (0 0 6 3) and (0 7), after adding the two linked list resultant linked list will be (7 0).
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
  Node* reverse( Node* temp){
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
    //Function to add two numbers represented by linked list.
     Node* addTwoLists( Node* num1,  Node* num2)
    {
        // code here
    while(num1->data==0){
        num1=num1->next;
         if(num1==NULL) break;

    }
    while(num2->data==0){
        num2=num2->next;
        if(num2==NULL) break;
    }
    if(num1==NULL && num2==NULL) return new Node(0);
     Node* t1=reverse(num1);
     Node* t2=reverse(num2);
    
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
    return reverse(dummy->next);
    }

 int main(){
    vector<int> arr{0,0,6,3};
    vector<int> arr2{0,0,7};
    Node* head1=convertLL(arr);
    Node* head2=convertLL(arr2);
    traversal(head1);
    traversal(head2);
    Node* newhead=addTwoLists(head1,head2);
    traversal(newhead);
    return 0;
}
