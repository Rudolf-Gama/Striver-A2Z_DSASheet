#include<bits/stdc++.h>
using namespace std;
 int sumSubarrayMins(int N, vector<int> &arr) {
        // code here
        int n=arr.size();
        int sum=0;
        int mod=(int)(1e9+7);
        for(int i=0;i<n;i++){
            int mini=arr[i];
            for(int j=i;j<n;j++){
                mini=min(mini,arr[j]);
                sum+=(mini%mod);
            }
        }
        return sum;
    }
vector<int> nextsmaller(vector<int> &arr,int n){
        vector<int> nse(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i])
            st.pop();
            
            nse[i]=st.empty() ? n:st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> prevsmaller(vector<int> &arr,int n){
        vector<int> pse(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i])
            st.pop();
            
            pse[i]=st.empty() ? -1: st.top();
            st.push(i);
        }
        return pse;
    }
    int sumSubarrayMinsOP(int N, vector<int> &arr) {
        // code here
        int n=arr.size();
        int sum=0;
        int mod=(int)(1e9+7);
        vector<int> pse=prevsmaller(arr,n);
        vector<int> nse=nextsmaller(arr,n);
        for(int i=0;i<n;i++){
           int l=i-pse[i];
           int r=nse[i]-i;
           
           sum=(sum+(l*r*1LL*arr[i])%mod)%mod;
        }
        return sum;
    }
    int main(){
        vector<int> arr{3,1,2,4};
        cout<<sumSubarrayMinsOP(arr.size(),arr);
        return 0;
    }