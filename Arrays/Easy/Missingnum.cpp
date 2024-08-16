#include<bits/stdc++.h>
using namespace std;

 int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum=(n*(n+1))/2;
        int sum1=0;
        for(int i=0;i<n;i++){
            sum1+=nums[i];
        }
        return (sum-sum1);
    }
 int missingNumberOP(vector<int>&nums){
     int xor1=0,xor2=0,n=nums.size();
     for(int i=0;i<n;i++){
        xor2=xor2^nums[i];
        xor1=xor1^(i+1);
     }
 return (xor1^xor2);
 }

int main()
{
        vector<int> nums{0,2,3,4};
        int a=missingNumberOP(nums);
        cout<<a;
        return 0;
        
 }