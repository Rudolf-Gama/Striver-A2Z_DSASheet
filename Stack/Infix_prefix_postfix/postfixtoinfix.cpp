 #include<bits/stdc++.h>
 using namespace std;
 string postToInfix(string exp) {
        // Write your code here
        stack<string> st;
        int i=0;
        while(i<exp.length()){
            if((exp[i]>='A' && exp[i]<='Z') ||
               (exp[i]>='a' && exp[i]<='z') ||
               (exp[i]>='0' && exp[i]<='9'))
               {
                   st.push(string(1,exp[i])); 
               }
            else{
                string l=st.top();
                st.pop();
                string f=st.top();
                st.pop();
                string com='('+f+exp[i]+l+')';
                st.push(com);
            }
            i++;
        }
        return st.top();
    }
    string postToInfixOP(string exp) {
        // Write your code here
        stack<string> st;
        int i=0;
        while(i<exp.length()){
            if((exp[i]>='A' && exp[i]<='Z') ||
               (exp[i]>='a' && exp[i]<='z') ||
               (exp[i]>='0' && exp[i]<='9'))
               {
                   st.push(string(1,exp[i])); 
               }
            else{
                string l=st.top();
                st.pop();
                string f=st.top();
                st.pop();
                st.push('('+f+exp[i]+l+')');
            }
            i++;
        }
        return st.top();
    }

    int main(){
        string s="AB-DE+F*/";
        cout<<postToInfixOP(s);
    }