#include<bits/stdc++.h>
using namespace std;

void mer(int arr[],int low,int mid,int high,int n){
  int left=low,right=mid+1;
  int temp[n]={0};
  int index=0;
  while(left<=mid && right<=high){
     if(arr[left]<=arr[right])
     {
        temp[index]=arr[left];
        left++;
     }
     else {
        temp[index]=arr[right];
        right++;
     }
     index++;
  }
  while(left<=mid){
    temp[index++]=arr[left++];
  }
//   while(left<=mid){
//     temp[index]=arr[left];
//     left++;
//     index++;
//   }
  while(right<=high){
    temp[index++]=arr[right++];
  }
  for(int i=low;i<=high;i++){
    arr[i]=temp[i-low];
  }
}

void mergesort(int arr[],int low,int high,int n){
if(low>=high) return;
int mid=(low+high)/2;
mergesort(arr,low,mid,n);
mergesort(arr,mid+1,high,n);
mer(arr,low,mid,high,n);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    cout<<"The array elements are"<<endl;
    for(int i=0;i<n;i++) cin>>arr[i];
    mergesort(arr,0,n-1,n);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}

// vector<int> vect(6); 
//     for(auto & x: vect) cin>>x;
//     for (int x : vect) 
//         cout << x << " "; 

