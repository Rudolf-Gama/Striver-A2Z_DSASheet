#include<bits/stdc++.h>
using namespace std;

int team(vector <int> & skill, int n)
{
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(skill[i]>2*skill[j])
              cnt++;
        }
    }
    return cnt;
}

void mer(vector<int>&arr,int low,int mid,int high){
  int left=low,right=mid+1;
  vector<int> temp;
  while(left<=mid && right<=high){
     if(arr[left]<=arr[right])
     {
        temp.push_back(arr[left]);
        left++;
     }
     else {
        temp.push_back(arr[right]);
        right++;
     }
  }
  while(left<=mid){
    temp.push_back(arr[left++]);
  }

  while(right<=high){
    temp.push_back(arr[right++]);
  }
  for(int i=low;i<=high;i++){
    arr[i]=temp[i-low];
  }
}
int reversepair(vector<int> &arr,int low,int mid,int high)
{
    int cnt=0;
    int right=mid+1;
    for(int i=low;i<=mid;i++){
    while (right <= high && arr[i] > (2 * arr[right]) ){
         right++ ;
    }
     cnt+=(right-(mid+1));
    }
    return cnt;
}
int mergesort(vector<int> &arr,int low,int high){
 int cnt=0;
if(low>=high) return cnt ;
int mid=(low+high)/2;
cnt+=mergesort(arr,low,mid);
cnt+=mergesort(arr,mid+1,high);
cnt+=reversepair(arr,low, mid, high);
mer(arr,low,mid,high);
return cnt;
}

int teamOP(vector<int> &skill, int n) {
return mergesort(skill,0,n-1);
}


void merge(vector<int>&nums, int low, int high, int mid) {
        int i = mid, j = mid+1;
        while(i >= 0 and j <= high) {
            if(nums[i] > nums[j]) swap(nums[i--], nums[j++]);
            else break;
        }
        sort(nums.begin()+low, nums.begin()+mid+1);
        sort(nums.begin()+mid+1, nums.begin()+high+1);
    }

    int countPairs(vector<int> &nums, int low, int high, int mid) {
        int cnt = 0;
        int right = mid+1;
        for(int i = low; i <= mid; ++i) {
            while(right <= high and nums[i] > (long long)2*nums[right]) ++right;
            cnt += (right-mid-1);
        }
        return cnt;
    }
    int mergeSort(vector<int> &nums, int low, int high) {
        int cnt = 0;
        if(low >= high) return cnt;
        int mid = low + (high-low)/2;
        cnt += mergeSort(nums, low, mid);
        cnt += mergeSort(nums, mid+1, high);
        cnt += countPairs(nums, low, high, mid);
        merge(nums, low, high, mid);
        return cnt;
    }
    int countRevPairs(int n, vector<int> arr) {
     
        return mergeSort(arr, 0, n-1);
    }

int main(){
    vector<int> skill{4 ,1, 2 ,3 ,1};
    cout<<teamOP(skill,skill.size());
    cout<<countRevPairs(skill.size(),skill);
    return 0;
}

