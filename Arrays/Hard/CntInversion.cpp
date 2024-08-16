#include<bits/stdc++.h>
using namespace std;

int numberOfInversionsBP(vector<int>&a, int n) {
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]) cnt++;
        }
    }
    return cnt;
}

int mer(vector<int>&arr,int low,int mid,int high){
  int left=low,right=mid+1;
  vector<int> temp;
  int cnt=0;
  while(left<=mid && right<=high){
     if(arr[left]<=arr[right])
     {
        temp.push_back(arr[left]);
        left++;
     }
     else {
        temp.push_back(arr[right]);
        cnt+=(mid-left+1);
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
  return cnt;
}

int mergesort(vector<int> &arr,int low,int high){
 int cnt=0;
if(low>=high) return cnt ;
int mid=(low+high)/2;
cnt+=mergesort(arr,low,mid);
cnt+=mergesort(arr,mid+1,high);
cnt+=mer(arr,low,mid,high);
return cnt;
}

int numberOfInversions(vector<int>&a, int n) {
    int cnt1=0;
    cnt1=mergesort(a,0,n-1);
    return cnt1;
}
int main(){
    vector<int> arr{5,3,2,4,1};
    cout<<numberOfInversions(arr,arr.size());
    return 0;
}