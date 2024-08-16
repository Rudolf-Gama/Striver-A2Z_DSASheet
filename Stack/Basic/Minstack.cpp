#include<bits/stdc++.h>
using namespace std;

class MinStack{
    int minEle;
    stack<int> st;
    public:
    /*returns min element from stack*/
       int getMin(){
           //Write your code here
           if(st.empty()) return -1;
           return minEle;
       }
       
       /*returns poped element from stack*/
       int pop(){
           //Write your code here
           if(st.empty()) return -1;
           int x=st.top();
           st.pop();
           if(x<minEle){
               int prevmin=minEle;
               minEle=2*minEle-x;
               return prevmin;
           }
           return x;
       }
       
       /*push element x into the stack*/
       void push(int x){
           //Write your code here
           if(st.empty()){
               minEle=x;
               st.push(x);
           }
           else{
               if(x<minEle)
               {
                   st.push(2*x-minEle);
                   minEle=x;
               }
               else{
                   st.push(x);
               }
           }
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