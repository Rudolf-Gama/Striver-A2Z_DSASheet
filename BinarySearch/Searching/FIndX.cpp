#include<bits/stdc++.h>
using namespace std;

int search(vector<int> &nums, int target) {
    int n=nums.size();
    int low=0,high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]==target) return mid;
        else if(nums[mid]>target)
            high=mid-1;
            else 
            low=mid+1;
    }
    return -1;
}

int binary(vector<int> &nums,int low,int high,int target){
    if(low>high) return -1;
     int mid=low+(high-low)/2;
      if(nums[mid]==target) return mid;
        else if(nums[mid]>target)
        return binary(nums,low,mid-1,target);
       return binary(nums,mid+1,high,target);
    }

int searchRecursion(vector<int> &nums, int target) {
   int n=nums.size();
    return binary(nums, 0,n-1,target) ;
}
int main(){
    vector<int> nums{1,2,4,5,6,7,8,9};
    int target;
    cin>>target;
    cout<<"Index is "<<searchRecursion(nums,target);
    return 0;
}