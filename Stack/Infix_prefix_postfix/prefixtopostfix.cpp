#include<bits/stdc++.h>
using namespace std;
 string preToPost(string pre_exp) {
        stack<string> st;
        int i=pre_exp.length()-1;
        while(i>=0){
            if(isalnum(pre_exp[i]))
               {
                   st.push(string(1,pre_exp[i])); 
               }
            else{
                string f=st.top();
                st.pop();
                string l=st.top();
                st.pop();
                st.push(f+l+pre_exp[i]);
            }
            i--;
        }
        return st.top();
    }

    int main(){
        string pre_exp = "/-AB*+DEF";
        cout << preToPost(pre_exp);
    }