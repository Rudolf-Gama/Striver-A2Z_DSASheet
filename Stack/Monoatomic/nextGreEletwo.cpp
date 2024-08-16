#include<bits/stdc++.h>
using namespace std;

  vector<int> nextGreaterElementBP(int N, vector<int>& arr) {
        // code here
        vector<int> ans(N,-1);
        for(int i=0;i<N;i++){
            for(int j=i+1;j<i+N;j++){
                if(arr[j%N]>arr[i])
                {
                ans[i]=arr[j%N];
                break;
                }
            }
        }
        return ans;
  }
  
  vector<int> nextGreaterElementOP(int N, vector<int>& arr) {
        // code here
        vector<int> ans(N);
        stack<int> st;
        for(int i=2*N-1;i>=0;i--){
            while(!st.empty() && st.top()<=arr[i%N])
            st.pop();
            
            if(i<N){
                ans[i]= st.empty()? -1: st.top();
            }
            st.push(arr[i%N]);
        }
        return ans;
    }
    int main(){
        vector<int> arr{2,10,12,1,11};
        vector<int> ans=nextGreaterElementOP(arr.size(),arr);
        for(auto it: ans){
            cout<<it<<" ";
        }
        return 0;
    }
