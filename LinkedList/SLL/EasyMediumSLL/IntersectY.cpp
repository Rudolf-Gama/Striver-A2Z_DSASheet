#include<bits/stdc++.h>
using namespace std;

class node {
    public:
        int num;
        node* next;
        node(int val) {
            num = val;
            next = NULL;
        }
};
void insertNode(node* &head,int val) {
    node* newNode = new node(val);
    if(head == NULL) {
        head = newNode;
        return;
    }
    
    node* temp = head;
    while(temp->next != NULL) temp = temp->next;
    
    temp->next = newNode;
    return;
}

node* intersectionPresent(node* head1,node* head2) {
    while(head2 != NULL) {
        node* temp = head1;
        while(temp != NULL) {
            //if both nodes are same
            if(temp == head2) return head2;
            temp = temp->next;
        }
        head2 = head2->next;
    }
    return NULL;
}


void printList(node* head) {
    while(head->next != NULL) {
        cout<<head->num<<"->";
        head = head->next;
    }
    cout<<head->num<<endl;
}

node* intersectionPresentBP(node *firstHead, node *secondHead)
{
    //Write your code here
    if(firstHead==NULL || secondHead==NULL ) return NULL;
    node* temp1=firstHead;
    node* temp2=secondHead;
    map<node*,int> mpp;
    while(temp1!=NULL){
        mpp[temp1]=1;
        temp1=temp1->next;
    }
    while(temp2!=NULL){
        if(mpp.find(temp2)!=mpp.end()){
            return temp2;
        }
        temp2=temp2->next;
    }
    return nullptr;
}

node* collision(node *fHead, node *sHead,int d){
    while(d){
        sHead=sHead->next;
        d--;
    }
    while(fHead!=sHead){
         fHead=fHead->next;
         sHead=sHead->next;
    }
    return fHead;
}

node* findIntersection(node *firstHead, node *secondHead)
{
    if(firstHead==NULL || secondHead==NULL ) return NULL;
    node* temp1=firstHead;
    node* temp2=secondHead;
    int n1=0, n2=0;
    while(temp1){
        temp1=temp1->next;
        n1++;
    }
    while(temp2){
        temp2=temp2->next;
        n2++;
    }
    if(n1>n2){
        return collision(secondHead,firstHead,n1-n2);
    }
    else{
        return collision(firstHead,secondHead,n2-n1);
    }
}

node* findIntersectionOP(node *firstHead, node *secondHead)
{
    //Write your code here
    node* temp1=firstHead;
    node* temp2=secondHead;
    if(temp1==NULL || temp2==NULL) return NULL;
    while(temp1!=temp2){
        temp1=temp1->next;
        temp2=temp2->next;
        if(temp1==temp2) return temp1;
        if(temp1==NULL) temp1=secondHead;
        if(temp2==NULL) temp2=firstHead;
    }
    return temp1;
}

int main() {
    // creation of both lists 
    node* head = NULL;
    insertNode(head,1);
    insertNode(head,3);
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,4);
    node* head1 = head;
    head = head->next->next;
    node* headSec = NULL;
    insertNode(headSec,3);
    node* head2 = headSec;
    headSec->next = head;
    //printing of the lists
    cout<<"List1: "; printList(head1);
    cout<<"List2: "; printList(head2);
    //checking if intersection is present
    // node* answerNode = intersectionPresentBP(head1,head2);
    node* answerNode =findIntersection (head1,head2);
    if(answerNode == NULL )
    cout<<"No intersection\n";
    else
    cout<<"The intersection point is "<<answerNode->num<<endl;
    return 0;
}