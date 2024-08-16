#include<bits/stdc++.h>
using namespace std;
vector<int> prevgreater(int price[],int n){
       vector<int> ans(n);
       stack<int> st;
       
       for(int i=0;i<n;i++){
           
           while(!st.empty() && price[st.top()]<=price[i])
            st.pop();
           
           ans[i]= st.empty() ? -1: st.top() ;
           
           st.push(i);
       }
       return ans;
    }
    
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       vector<int> pge=prevgreater(price,n);
       vector<int> ans(n);
       for(int i=0;i<n;i++){
           ans[i]=i-pge[i];
       }
       return ans;
    }
    
     vector <int> calculateSpanOP(int price[], int n)
    {
       // Your code here
       vector<int> ans(n);
       stack<int> st;
       
       for(int i=0;i<n;i++){
           
           while(!st.empty() && price[st.top()]<=price[i])
            st.pop();
           
           ans[i]=i-(st.empty() ? -1: st.top());
           
           st.push(i);
       }
       return ans;
    }

    int main(){
        int price[]={7,2,1,3,3,1,8};
        int n=sizeof(price)/sizeof(price[0]);
        vector<int> ans=calculateSpan(price,n);
        for(auto it: ans){
            cout<<it<<" ";
        }
        return 0;
    }