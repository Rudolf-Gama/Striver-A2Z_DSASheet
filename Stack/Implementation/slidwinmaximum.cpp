#include<bits/stdc++.h>
using namespace std;
 vector <int> max_of_subarrays(int arr[], int n, int k)
    {
        // your code here
        int maxi=INT_MIN;
        vector<int> ans;
        for(int i=0;i<k;i++){
            maxi=max(maxi,arr[i]);
        }
        ans.push_back(maxi);
        for(int i=k;i<n;i++){
            if(arr[i]>maxi){
                maxi=arr[i];
            }
            else if(maxi==arr[i-k]){
                maxi= *max_element(arr+i-k+1,arr+i+1);
            }
             ans.push_back(maxi);
        }
        return ans;
    }

    vector <int> max_of_subarraysOP(int arr[], int n, int k)
    {
        // your code here
        vector<int> ans;
        deque<int> dq;
        for(int i=0;i<n;i++){
            if(!dq.empty() && dq.front()<=i-k)
              dq.pop_front();
              
            while(!dq.empty() && arr[dq.back()]<=arr[i])
             dq.pop_back();
            
            dq.push_back(i);
            if(i>=k-1){
                ans.push_back(arr[dq.front()]);
            }
        }
        return ans;
    }
int main(){
    int arr[]={1,3,-1,-3,5,3,2,1,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=3;
    vector<int> ans=max_of_subarrays(arr,n,k);
    for(auto it: ans){
        cout<<it<<" ";
    }
    return 0;
}