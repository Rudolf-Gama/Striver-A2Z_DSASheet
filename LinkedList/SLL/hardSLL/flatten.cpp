#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *child;

    // Constructors to initialize the
    // data, next, and child pointers
    Node() : data(0), next(nullptr), child(nullptr) {};
    Node(int x) : data(x), next(nullptr), child(nullptr) {}
    Node(int x, Node *nextNode, Node *childNode) :
                    data(x), next(nextNode), child(childNode) {}
};

void printOriginalLinkedList(Node* head, int depth) {
    while (head != nullptr) {
        cout << head->data;

        if (head->child) {
            cout << " -> ";
            printOriginalLinkedList(head->child, depth + 1);
        }

        if (head->next) {
            cout << endl;
            for (int i = 0; i < depth; ++i) {
                cout << "| ";
            }
        }
        head = head->next;
    }
}
Node* convert(vector<int> arr){
	if(arr.size()==0) return NULL;
	Node* head=new Node(arr[0]);
	Node* temp=head;
	for(int i=1;i<arr.size();i++){
		Node* newnode=new Node(arr[i]);
		temp->child=newnode;
		temp=newnode;
	}
	return head;
}
void printLinkedList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->child;
    }
    cout << endl;
}

Node* flattenLinkedListBP(Node* head) 
{
	// Write your code here
	vector<int> ans;
	Node* temp=head;
	while(temp!=NULL){
		Node* t1=temp;
		while(t1!=NULL){
			ans.push_back(t1->data);
			t1=t1->child;
		}
		temp=temp->next;
	}
	sort(ans.begin(),ans.end());
	return head=convert(ans);
}


Node* mergelist(Node* list1,Node* list2){
     Node* dummy=new Node(-1);
	 Node* res=dummy;
	 while(list1!=NULL && list2!=NULL){
		 if(list1->data<list2->data){
			 res->child=list1;
			 res=list1;
			 list1=list1->child;
		 }
		 else{
			 res->child=list2;
			 res=list2;
			 list2=list2->child;
		 }
		 res->next=NULL;
	 }
	 if(list1) res->child=list1;
	 else res->child=list2;

	 return dummy->child;
}

Node* flattenLinkedList(Node* head) 
{
	// Write your code here
	if(head==NULL || head->next==NULL){
		return head;
	}
	Node* newhead=flattenLinkedList(head->next);
	return mergelist(head,newhead);
}

int main() {
    // Create a linked list with child pointers
    Node* head = new Node(5);
    head->child = new Node(14);
    
    head->next = new Node(4);
    head->next->child = new Node(9);
    
    head->next->next = new Node(12);
    head->next->next->child = new Node(13);
    head->next->next->child->child = new Node(20);
    
    head->next->next->next = new Node(7);
    head->next->next->next->child = new Node(17);

    cout << "Original linked list:" << endl;
    printOriginalLinkedList(head, 0);

    Node* flattened = flattenLinkedList(head);
    cout << "\nFlattened linked list: ";
    printLinkedList(flattened);

    return 0;
}

