#include<bits/stdc++.h>
using namespace std;

 vector<int> leftSmaller(int n, int a[]){
        // code here
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(a[j]<a[i]){
                    ans[i]=a[j];
                    break;
                }
            }
        }
        return ans;
    }
    

    vector<int> leftSmallerOP(int n, int a[]){
        // code here
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i=0;i<n;i++){
           while(!st.empty() && st.top()>=a[i])
           st.pop();
           
           ans[i]=st.empty() ? -1: st.top();
           
           st.push(a[i]);
        }
        return ans;
    }


    int main(){
        int arr[]={4,5,2,10,8};
        int n=sizeof(arr)/sizeof(arr[0]);
        vector<int> ans=leftSmallerOP(n,arr);
        for(auto it: ans){
            cout<<it<<" ";
        }
        return 0;
    }