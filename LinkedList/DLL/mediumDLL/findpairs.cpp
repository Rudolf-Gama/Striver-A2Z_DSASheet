#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* prev;

    Node(int data1,Node* next1,Node* back1){
        data=data1;
        next=next1;
        prev=back1;
    }
    Node(int data1){
        data=data1;
        next=nullptr;
        prev=nullptr;
    }
};

Node* convertDLL(vector<int> arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node *temp=new Node(arr[i],nullptr,mover);
        mover->next=temp;
        mover=mover->next; 
    }
    return head;
}

void print(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

vector<pair<int, int>> findPairsBP(Node* head, int k)
{
    // Write your code here.
    Node* temp=head;
    vector<pair<int,int>> ans;
    while(temp!=NULL){
        Node* temp1=temp->next;
        while(temp1!=NULL&& (temp->data+temp1->data)<=k){
          if ((temp->data + temp1->data) == k) {
            ans.push_back({temp->data,temp1->data});
          }
           temp1=temp1->next;
        }
        temp=temp->next;
    }
    return ans;
}

vector<pair<int, int>> findPairs(Node* head, int k)
{
    // Write your code here.
    vector<pair<int,int>> ans;
     Node* temp=head;
     Node* left=head;
     while(temp->next!=NULL){
         temp=temp->next;
     }
     Node* right=temp;
     while(left->data<right->data){
         int sum=left->data+right->data;
         if(sum==k){
             ans.push_back({left->data,right->data});
             left=left->next;
             right=right->prev;
         }
         else if(sum<k){
               left=left->next;
         }
         else{
             right=right->prev;
         }
     }
   return ans;
}

int main(){
    vector<int> arr{1,3,5,7,9,13};
    int k;
    cin>>k;
    Node* head=convertDLL(arr);
    print(head);
    vector<pair<int,int>>ans=findPairs(head,k);
    for(auto i:ans){
        cout<<i.first<<" "<<i.second<<endl;
    }
    return 0;
}