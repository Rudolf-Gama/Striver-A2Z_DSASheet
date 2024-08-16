#include<bits/stdc++.h>
using namespace std;
string preToInfix(string pre_exp) {
        // Write your code here
        stack<string> st;
        int i=pre_exp.length()-1;
        while(i>=0){
            if((pre_exp[i]>='A' && pre_exp[i]<='Z') ||
               (pre_exp[i]>='a' && pre_exp[i]<='z') ||
               (pre_exp[i]>='0' && pre_exp[i]<='9'))
               {
                   st.push(string(1,pre_exp[i])); 
               }
            else{
                string f=st.top();
                st.pop();
                string l=st.top();
                st.pop();
                st.push('('+f+pre_exp[i]+l+')');
            }
            i--;
        }
        return st.top();
    }

    int main(){
        string s="*+PQ-MN";
        cout<<preToInfix(s);
        return 0;
    }