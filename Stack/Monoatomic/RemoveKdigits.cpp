#include<bits/stdc++.h>
using namespace std;
string removeKdigits(string S, int K) {
        int n=S.length();
        if(K>=n) return "0";
        stack<char> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && K>0 && (st.top()-'0')> (S[i]-'0'))
             st.pop(),K--;
            
            st.push(S[i]); 
        }
       
        while(K>0)
         st.pop(),K--;
         
        if(st.empty()) return "0";
        
        string ans;
    
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        
        int start=0;
        while(start<ans.length() && ans[start]=='0')
            start++;
        
        ans=ans.substr(start);
        
        return ans.empty() ? "0" : ans;
    }

    int main(){
        string S = "10200";
        int K = 1;
        cout<<removeKdigits(S,K);
        return 0;
    }