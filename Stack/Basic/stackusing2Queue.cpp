#include<bits/stdc++.h>
#include<queue>

using namespace std;

class QueueStack {
private:
    queue<int> q1;
    queue<int> q2;

public:
    void push(int x);
    int pop();
};

// Function to push an element into the stack using two queues.
// Using scope resolution operator :: is used to define a method that belongs to a specific class outside of the class definition.
void QueueStack::push(int x) {
    q2.push(x);
    while (!q1.empty()) {
        q2.push(q1.front());
        q1.pop();
    }
    swap(q1, q2);
}

// Function to pop an element from the stack using two queues.
int QueueStack::pop() {
    if (q1.empty()) return -1;
    int x = q1.front();
    q1.pop();
    return x;
}

// Optional: A main function to demonstrate the functionality
int main() {
    QueueStack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << stack.pop() << endl; // Output: 30
    cout << stack.pop() << endl; // Output: 20
    cout << stack.pop() << endl; // Output: 10
    cout << stack.pop() << endl; // Output: -1 (stack is empty)

    return 0;
}
