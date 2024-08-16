#include<bits/stdc++.h>
using namespace std;

 string removeOuter(string& s) {
        // code here
       stack<int> st;
       string ans="";
       for(int i=0;i<s.length();i++){
           if(s[i]=='('){
               if(!st.empty())
               ans.push_back(s[i]);
               st.push(s[i]);
           }
           else{
               st.pop();
               if(!st.empty())
               ans.push_back(s[i]);
           }
       }
       return ans;
    }

string removeOuterOP(string& s) {
        // code here
        string ans="";
        int cnt=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==')') cnt--;
            if(cnt!=0) ans.push_back(s[i]);
            if(s[i]=='(') cnt++;
        }
        return ans;
    }

int main(){
    string s;
    cin>>s;
    cout<<removeOuter(s);
    return 0;
}
