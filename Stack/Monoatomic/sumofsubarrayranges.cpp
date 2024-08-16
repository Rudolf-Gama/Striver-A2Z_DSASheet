#include<bits/stdc++.h>
using namespace std;
long long subarrayRanges(int N, vector<int> &arr) {
        // code here
        long long sum=0L;
        for(int i=0;i<arr.size();i++){
            int  mini=arr[i],maxi=arr[i];
            for(int j=i;j<arr.size();j++){
                mini=min(arr[j],mini);
                maxi=max(arr[j],maxi);
                sum+=(maxi-mini);
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
    vector<int> nextgreater(vector<int> &arr,int n){
        vector<int> nge(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]<=arr[i])
            st.pop();
            
            nge[i]=st.empty() ? n:st.top();
            st.push(i);
        }
        return nge;
    }
    
    vector<int> prevgreater(vector<int> &arr,int n){
        vector<int> pge(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]<arr[i])
            st.pop();
            
            pge[i]=st.empty() ? -1: st.top();
            st.push(i);
        }
        return pge;
    }
    
    long long sumSubarrayMins(int n, vector<int> &arr) {
        long long sum=0L;
        vector<int> pse=prevsmaller(arr,n);
        vector<int> nse=nextsmaller(arr,n);
        int mod = 1000000007;
        for(int i=0;i<n;i++){
           int l=i-pse[i];
           int r=nse[i]-i;
           
            sum = (sum + (1LL * l * r * arr[i]) % mod) % mod;
        }
        return sum;
    }
    
    long long sumSubarrayMaxs(int n, vector<int> &arr) {
        long long sum=0L;

        vector<int> pge=prevgreater(arr,n);
        vector<int> nge=nextgreater(arr,n);
        int mod = 1000000007;
        for(int i=0;i<n;i++){
           int l=i-pge[i];
           int r=nge[i]-i;
            sum = (sum + (1LL * l * r * arr[i]) % mod) % mod;
        }
        return sum;
    }
    
    long long subarrayRangesOP(int N, vector<int> &arr) {
        // code here
        return sumSubarrayMaxs(N,arr)-sumSubarrayMins(N,arr);
    }
int main(){
    vector<int> arr{1,4,3,2};
    cout<<subarrayRangesOP(arr.size(),arr);
    return 0;
}