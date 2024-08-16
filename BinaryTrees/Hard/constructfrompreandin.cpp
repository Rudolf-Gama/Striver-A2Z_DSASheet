
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// // } Driver Code Ends

// /*Complete the code here.
// Node is as follows:
// struct Node
// {
//   int data;
//   Node* left;
//   Node* right;
// };
// */
// class Solution{
//     public:
//     Node* tree(int in[],int inS,int inE,int pre[],int preS,int preE,map<int,int>mpp){
//         if(inS>inE || preS>preE) return NULL;
//         Node* root=new Node(pre[preS]);
//         int inroot=mpp[root->data];
//         int numsleft=inroot-inS;
        
//         root->left=tree(in,inS,inroot-1,pre,preS+1,preS+numsleft,mpp);
//         root->right=tree(in,inroot+1,inE,pre,preS+numsleft+1,preE,mpp);
        
//         return root;
//     }
   
//     Node* buildTree(int in[],int pre[], int n)
//     {
//         // Code here
//         map<int,int> mpp;
//         for(int i=0;i<n;i++){
//             mpp[in[i]]=i;
//         }
        
//         Node* root= tree(in,0,n-1,pre,0,n-1,mpp);
//         return root;
//     }
// };

// //{ Driver Code Starts.
// int main()
// {
// 	int t;
// 	cin>>t;
// 	while(t--)
// 	{
// 		int n;
// 		cin>>n;
		
// 		int inorder[n], preorder[n];
// 		for(int i=0; i<n; i++)
// 			cin>> inorder[i];
// 		for(int i=0; i<n; i++)
// 			cin>> preorder[i];
// 		Solution obj;
// 		Node *root = obj.buildTree(inorder, preorder, n);
// 		printPostOrder(root);
// 		cout<< endl;
// 	}
// }

// // } Driver Code Ends


   Node* tree(int in[], int inS, int inE, int pre[], int preS, int preE, map<int, vector<int>> &mpp, map<int, int> &countnodes) {
    if (inS > inE || preS > preE) return NULL;

    Node* root = new Node(pre[preS]);
    int inroot = mpp[root->data][countnodes[root->data]++];
    int numsleft = inroot - inS;

    root->left = tree(in, inS, inroot - 1, pre, preS + 1, preS + numsleft, mpp, countnodes);
    root->right = tree(in, inroot + 1, inE, pre, preS + numsleft + 1, preE, mpp, countnodes);

    return root;
    }

Node* buildTree(int in[], int pre[], int n) {
    map<int, vector<int>> mpp;
    map<int, int> countnodes;

    for (int i = 0; i < n; i++) {
        mpp[in[i]].push_back(i);
        countnodes[in[i]] = 0;
    }

    return tree(in, 0, n - 1, pre, 0, n - 1, mpp, countnodes);
}

int main(){
    int n=6;
    int in[] = {40,20,50,10,60,30};
    int pre[] = {10,20,40,30,50,60};
    Node* root=buildTree(in,pre,n);
    printPostOrder(root);
    return 0;
}