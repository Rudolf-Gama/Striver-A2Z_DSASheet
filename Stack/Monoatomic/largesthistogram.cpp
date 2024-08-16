#include<bits/stdc++.h>
using namespace std;
 vector<long long> nextsmaller(long long arr[],int n){
        vector<long long> nse(n);
        stack<long long> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i])
            st.pop();
            
            nse[i]=st.empty() ? n:st.top();
            st.push(i);
        }
        return nse;
    }
    vector<long long> prevsmaller(long long arr[],int n){
        vector<long long> pse(n);
        stack<long long> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i])
            st.pop();
            
            pse[i]=st.empty() ? -1: st.top();
            st.push(i);
        }
        return pse;
    }
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        long long area=0LL;
        vector<long long> nse=nextsmaller(arr,n);
        vector<long long> pse=prevsmaller(arr,n);

        for(int i=0;i<n;i++){
            area=max(area,arr[i]*(nse[i]-pse[i]-1));
        }
        return area;
    }
    
   long long getMaxAreaOP(long long arr[], int n)
    {
        // Your code here
        stack<int> st;
        long long area=0L;
        for(int i=0;i<n;i++){
            
            while(!st.empty() && arr[st.top()]>arr[i]){
                int ele=st.top();
                st.pop();
                int nse=i;
                int pse=st.empty()?-1 :st.top();
                area=max(area,arr[ele]*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
                int ele=st.top();
                st.pop();
                int nse=n;
                int pse=st.empty()?-1 :st.top();
                area=max(area,arr[ele]*(nse-pse-1));
        }
        return area;
    }
    int main(){
        long long arr[]={6,2,5,4,5,1,6};
        int n=sizeof(arr)/sizeof(arr[0]);
        cout<<getMaxAreaOP(arr,n);
        return 0;
    }