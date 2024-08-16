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
Node* sortList(Node *head){
    // Write your code here.
    Node* temp=head;
    int cnt0=0,cnt1=0,cnt2=0;
    while(temp!=NULL){
        if(temp->data==0){
            cnt0++;
        }
        else if (temp->data==1)
            cnt1++;
            else{
                cnt2++;
            }
            temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        if(cnt0){
            temp->data=0;
            cnt0--;
        }
        else if (cnt1){
            temp->data=1;
            cnt1--;
        }
        else {
            temp->data=2;
            cnt2--;
        }
        temp=temp->next;
    }
    return head;
}

Node* sortListOP(Node *head){
    // Write your code here.
    if(head==nullptr || head->next==nullptr) return head;
    Node* temp=head;
    Node* oneH=new Node(-1);
    Node* twoH=new Node(-1);
    Node* zeroH=new Node(-1);
     Node* zero=zeroH;
     Node* one=oneH;
     Node* two=twoH;

     while(temp!=NULL){
         if(temp->data==0){
             zero->next=temp;
             zero=temp;
         }
         else if (temp->data==1){
             one->next=temp;
             one=temp;
         }
         else{
             two->next=temp;
             two=temp;
         }
         temp=temp->next;
     }

     zero->next=(oneH->next)? (oneH->next) : (twoH->next);
     one->next=twoH->next;
     two->next=NULL;
     
     Node* newhead=zeroH->next;
     delete oneH;
     delete twoH;
     delete zeroH;
     
     return newhead;
}
    int main(){
    vector<int> arr{1,2,2,0,0,2,1,0};
    Node* head=convertLL(arr);
    traversal(head);
    Node* middle=sortListOP(head);
    traversal(middle);
    return 0;
}