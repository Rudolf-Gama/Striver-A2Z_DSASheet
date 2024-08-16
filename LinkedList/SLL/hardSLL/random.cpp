
#include <bits/stdc++.h>
using namespace std;


class Node {
public:
    int data;           
    Node *next;        
    Node *random;       

  
    Node() : data(0), next(nullptr), random(nullptr){};
    Node(int x) : data(x), next(nullptr), random(nullptr) {} 
    Node(int x, Node *nextNode, Node *randomNode) :
            data(x), next(nextNode), random(randomNode) {}  
};

Node *cloneLL(Node *head){
	// Write your code here
	unordered_map<Node*,Node*>mpp;
	Node* temp=head;
	while(temp!=NULL){
		Node* newnode=new Node(temp->data);
		mpp[temp]=newnode;
		temp=temp->next;
	}
	temp=head;
	while(temp!=NULL){
		Node* deepcopy=mpp[temp];
		deepcopy->next=mpp[temp->next];
		deepcopy->random=mpp[temp->random];
		temp=temp->next;
	}
	return mpp[head];
}


Node* insertNode(Node* head){
     Node* temp=head;
	 while(temp!=nullptr){
		 Node* newnode=new Node(temp->data);
		 newnode->next=temp->next;
		 temp->next=newnode;
		 temp=temp->next->next;
	 }
	 return head;
}
Node* random(Node* head){
	  Node* temp=head;
	  while(temp!=nullptr){
		  Node* copynode=temp->next;
		  if(temp->random)
		  copynode->random=temp->random->next;
		  else
		  copynode->random=nullptr;
		  temp=temp->next->next;
	  }
	  return head;
}
Node* pointnext(Node* head){
	 Node* temp=head;
	 Node* dummy=new Node(-1);
	 Node* res=dummy;
	 while(temp!=NULL){
		 res->next=temp->next;
		 temp->next=temp->next->next;

		 res=res->next;
		 temp=temp->next;
	 }
	 return dummy->next;
}

Node *cloneLLOP(Node *head){
	// Write your code here
	insertNode(head);
	random(head);
	return pointnext(head);
}


void printClonedLinkedList(Node *head) {
    while (head != nullptr) {
        cout << "Data: " << head->data;
        if (head->random) {
            cout << ", Random: " << head->random->data;
        } else {
            cout << ", Random: nullptr";
        }
        cout << endl;
         // Move to the next node
        head = head->next;  
    }
}
int main() {
    // Example linked list: 7 -> 14 -> 21 -> 28
    Node* head = new Node(7);
    head->next = new Node(14);
    head->next->next = new Node(21);
    head->next->next->next = new Node(28);
    head->next->next->next->next= new Node(35);

    // Assigning random pointers
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next;
    head->next->next->next->random = nullptr;
    head->next->next->next->next->random = head->next;

    cout << "Original Linked List with Random Pointers:" << endl;
    printClonedLinkedList(head);

    // Clone the linked list
    Node* clonedList = cloneLLOP(head);

    cout << "\nCloned Linked List with Random Pointers:" << endl;
    printClonedLinkedList(clonedList);

    return 0;
}