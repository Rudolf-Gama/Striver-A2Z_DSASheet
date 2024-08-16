#include <iostream>
#include <stack>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class BSTIterator {
    stack<Node*> st;
    bool reverse;
public:
    BSTIterator(Node* root, bool isReverse) : reverse(isReverse) {
        pushAll(root);
    }

    bool hasNext() {
        return !st.empty();
    }

    int next() {
        Node* tmpNode = st.top();
        st.pop();
        if (!reverse) pushAll(tmpNode->right);
        else pushAll(tmpNode->left);
        return tmpNode->data;
    }

private:
    void pushAll(Node* node) {
        while (node != NULL) {
            st.push(node);
            if (!reverse) node = node->left;
            else node = node->right;
        }
    }
};

bool isPairPresent(Node* root, int target) {
    if (!root) return false;

    BSTIterator l(root, false);
    BSTIterator r(root, true);  
    int i = l.next();
    int j = r.next();

    while (i < j) {
        if (i + j == target) return true;
        else if (i + j < target) i = l.next();
        else j = r.next();
    }

    return false;
}

Node* insert(Node* node, int key) {
    if (node == NULL) return new Node(key);
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    return node;
}

int main() {
    Node* root = NULL;
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 12);
    root = insert(root, 16);
    root = insert(root, 25);

    int target = 28;
    if (isPairPresent(root, target))
        cout << "Pair found" << endl;
    else
        cout << "No pair found" << endl;

    return 0;
}
