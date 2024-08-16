#include<bits/stdc++.h>
using namespace std;
vector<long long> nextLargerElementBP(vector<long long> arr, int n){
        // Your code here
        vector<long long> ans(n,-1);
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(arr[j]>arr[i])
                {
                    ans[i]=arr[j];
                    break;
                }
            }
        }
        return ans;
    }
  vector<long long> nextLargerElementOP(vector<long long> arr, int n){
        // Your code here
        vector<long long> ans(n);
        stack<long long> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=arr[i])
                st.pop();
            
            if(st.empty()) ans[i]=-1L;
            else ans[i]=st.top();
            
            st.push(arr[i]);
        }
        return ans;
    }
int main(){
    vector<long long> arr={1 ,3 ,2 ,4};
    vector<long long> ans=nextLargerElementOP(arr,arr.size());
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}    