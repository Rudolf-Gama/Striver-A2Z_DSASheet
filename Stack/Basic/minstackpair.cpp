#include <iostream>
#include <stack>
using namespace std;

class MinStack {
    stack<pair<int, int>> st;

public:
    /*returns min element from stack*/
    int getMin() {
        if (st.empty()) return -1;
        return st.top().second;
    }

    /*returns popped element from stack*/
    int pop() {
        if (st.empty()) return -1;
        int topElement = st.top().first;
        st.pop();
        return topElement;
    }

    /*push element x into the stack*/
    void push(int x) {
        int currentMin = st.empty() ? x : min(x, st.top().second);
        st.push({x, currentMin});
    }
};

int main() {
    MinStack minStack;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int op;
        cin >> op;
        if (op == 1) {
            int value;
            cin >> value;
            minStack.push(value);
        } else if (op == 2) {
            cout << minStack.pop() << " ";
        } else if (op == 3) {
            cout << minStack.getMin() << " ";
        }
    }
    return 0;
}