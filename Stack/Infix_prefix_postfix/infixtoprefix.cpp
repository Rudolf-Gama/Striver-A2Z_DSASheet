#include<bits/stdc++.h>
using namespace std;
int priority(char ch){
        if(ch=='^') return 3;
        else if(ch=='*' || ch=='/') return 2;
        else if(ch=='+'|| ch=='-') return 1;
        else return -1;
    }

string infixToPrefix(string s) {
        reverse(s.begin(),s.end());
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') s[i]=')';
            else if(s[i]==')') s[i]='(';
        }
        int i=0;
        stack<char> st;
        string ans;
        while(i<s.length()){
            if((s[i]>='A' && s[i]<='Z') ||
               (s[i]>='a' && s[i]<='z') ||
               (s[i]>='0' && s[i]<='9'))
               ans+=s[i];
            else if(s[i]=='(')
               st.push(s[i]);
            else if(s[i]==')'){
                while(!st.empty() && st.top()!='('){
                    ans+=st.top();
                    st.pop();
                }
                st.pop();
            }
            else{
                if(s[i]=='^'){
                    while(!st.empty() && priority(s[i])<=priority(st.top())){
                    ans+=st.top();
                    st.pop();
                   }
                }
                else {
                while(!st.empty() && priority(s[i])<priority(st.top())){
                    ans+=st.top();
                    st.pop();
                   }
                }
              st.push(s[i]);
            }
            i++;
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
}
int main(){
    string infix = "(A+B)*C-D+F";
    cout << infixToPrefix(infix) << endl;
}
