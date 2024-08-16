#include<bits/stdc++.h>
using namespace std;
int countSubarray(int n, vector<int>& nums, int k) {
        // Code here
        int maxcnt=0;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=i;j<n;j++){
                if(nums[j]&1) cnt++;
                if(cnt==k) maxcnt++;
                else if(cnt>k) break;
            }
        }
        return maxcnt;
    }

     int countsubarray(int N,vector<int>& arr,int k){
        if(k<0) return 0;
        int maxcnt=0;
        int sum=0;
        int r=0,l=0;
        while(r<N){
             sum+=(arr[r]&1);
            while(sum>k){
                sum-=(arr[l]&1);
                l++;
            }
            if(sum<=k ){
               maxcnt+=(r-l+1);
            }
            r++;
        }
        return maxcnt;
    }
    int countSubarrayOP(int n, vector<int>& nums, int k) {
        // Code here
        return (countsubarray(n,nums,k)-countsubarray(n,nums,k-1));
    }

     int countSubarrayop(int N, vector<int>& arr, int target) {
        // Code here
        int cntK=0;
        int cntmK=0;
        int sum=0,sum1=0;
        int r=0,l=0,l1=0;
        while(r<N){
            sum+=(arr[r]&1);
            sum1+=(arr[r]&1);
            while(sum>target){
                sum-=(arr[l]&1);
                l++;
            }
            while(sum1>target-1){
                sum1-=(arr[l1]&1);
                l1++;
            }
            if(sum<=target){
                cntK+=(r-l+1);
            }
            if(sum1<=target-1){
                cntmK+=(r-l1+1);
            }
            r++;
        }
        return (cntK-cntmK);
    }
    int main(){
        vector<int> arr{1,1,2,1,1};
        int k;
        cin>>k;
        cout<<countSubarray(arr.size(),arr,k);
        return 0;
    }