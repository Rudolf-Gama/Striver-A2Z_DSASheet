#include<bits/stdc++.h>
using namespace std;
int findAllSubarraysWithGivenSumOP(vector < int > & arr, int k){
 unordered_map<int,int> mpp;
    int presum=0;
    mpp[0]=1;
    int cnt=0;
    for(int i=0;i<arr.size();i++){
        presum+=arr[i];
        int remove=presum-k;
        cnt+=mpp[remove];
        mpp[presum]+=1;
    }

    return cnt;
}

int findAllSubarraysWithGivenSumBP(vector < int > & arr, int k) {
    int n=arr.size(); 
    int cnt=0;
   for(int i=0;i<n;i++){
       int sum=0;
       for(int j=i;j<n;j++){
           sum+=arr[j];
           if(sum==k) cnt++;
       }
   }
   return cnt;
}
int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
 
    int n=arr.size(); 
    int cnt=0;
   for(int i=0;i<n;i++){
       for(int j=i;j<n;j++){
             int sum=0;
           for(int k=i;k<=j;k++)
           sum+=arr[k];
           if(sum==k) cnt++;
       }
   }
   return cnt;
}
int main(){
    vector<int> arr{1,2,3,-3,1,1,1,4,2,-3};
    int k;
    cin>>k;
    cout<<findAllSubarraysWithGivenSumBP(arr,k);
    return 0;
}