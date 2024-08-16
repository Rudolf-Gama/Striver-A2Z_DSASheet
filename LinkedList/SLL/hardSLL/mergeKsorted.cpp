//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

// } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class Solution{
  public:
    //Function to merge K sorted linked list.
    Node* convert(vector<int> arr){
        Node* head=new Node(arr[0]);
        Node* temp=head;
        for(int i=1;i<arr.size();i++){
            Node* newnode=new Node(arr[i]);
            temp->next=newnode;
            temp=newnode;
        }
        return head;
    }
    Node * mergeKLists(Node *arr[], int K)
    {
           // Your code here
           vector<int>ans;
           for(int i=0;i<K;i++){
               Node* temp=arr[i];
               while(temp!=NULL){
                  ans.push_back(temp->data);
                  temp=temp->next;
               }
           }
           sort(ans.begin(),ans.end());
          return convert(ans);
    }

//     Node* sortedMerge(Node* head1, Node* head2)  
//    {  
//     // code here
//     Node* dummy=new Node(-1);
//     Node* temp=dummy;
//     Node* temp1=head1;
//     Node* temp2=head2;
//     while(temp1!=NULL && temp2!=NULL){
//         if(temp1->data<temp2->data){
//             temp->next=temp1;
//             temp=temp1;
//             temp1=temp->next;
//         }
//         else{
//             temp->next=temp2;
//             temp=temp2;
//             temp2=temp2->next;
//         }
//     }
//     if(temp1) temp->next=temp1;
//     else temp->next=temp2;

//     return (dummy->next);
//     } 

//     Node * mergeKLists(Node *arr[], int K)
//     {
//         // Your code here
//         Node* head=arr[0];
//         for(int i=1;i<K;i++){
//             Node* newhead=arr[i];
//             head=sortedMerge(head,newhead);
//         }
//         return head;
//     }


//  Node * mergeKLists(Node *arr[], int K)
//     {
//            // Your code here
//            priority_queue<pair<int,Node*>,
//            vector<pair<int,Node*>>,greater<pair<int,Node*>>>pq;
//            for(int i=0;i<K;i++){
//                if(arr[i])
//                pq.push({arr[i]->data,arr[i]});
//            }
//            Node* dummy=new Node(-1);
//            Node* temp=dummy;
//            while(!pq.empty()){
//                auto it=pq.top();
//                temp->next=it.second;
//                pq.pop();
               
//                if(it.second->next)
//                pq.push({it.second->next->data,it.second->next});
               
//                temp=temp->next;
//            }
//         return dummy->next;
//     }
};



//{ Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
       cout<<"Enter the value of K"<<endl;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cout<<"Enter the size of LL"<<endl;
           cin>>n;

           int x;
           cout<<"Enter the elements of LL"<<endl;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
        cout<<"The sorted list is"<<endl;
		printList(res);

   }

	return 0;
}

// } Driver Code Ends