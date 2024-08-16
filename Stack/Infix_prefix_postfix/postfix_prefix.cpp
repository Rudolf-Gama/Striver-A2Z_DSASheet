#include<bits/stdc++.h>
using namespace std;
 string postToPre(string post_exp) {
        // Write your code here
        stack<string> st;
        int i=0;
        while(i<post_exp.length()){
            if((post_exp[i]>='A' && post_exp[i]<='Z') ||
               (post_exp[i]>='a' && post_exp[i]<='z') ||
               (post_exp[i]>='0' && post_exp[i]<='9'))
               {
                   st.push(string(1,post_exp[i])); 
               }
            else{
                string l=st.top();
                st.pop();
                string f=st.top();
                st.pop();
                st.push(post_exp[i]+f+l);
            }
            i++;
        }
        return st.top();
    }

    int main(){
        string s="AB-DE+F*/";
        cout<<postToPre(s);
    }