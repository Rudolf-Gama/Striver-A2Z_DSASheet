#include<bits/stdc++.h>
using namespace std;
int first(vector<int> arr, int n, int x) {
	int low=0;
	int high=n-1;
	int ans=-1;
	while(low<=high){
		int mid=low+(high-low)/2;
		if(arr[mid]==x){
			ans=mid;
			high=mid-1;
		}
        else if(arr[mid]>x)
            high=mid-1;
		else 
		 low=mid+1;
	}
	return ans;
}
int last(vector<int> arr, int n, int x) {
	int low=0;
	int high=n-1;
	int ans=-1;
	while(low<=high){
		int mid=low+(high-low)/2;
	    if(arr[mid]==x){
			ans=mid;
			low=mid+1;
		}
        else if(arr[mid]>x)
            high=mid-1;
		else 
		  low=mid+1;
	}
	return ans;
}
int count(vector<int>& arr, int n, int x) {
  int lb=first(arr,n,x);
   if(lb==-1) return {0};
   int Ub=last(arr,  n, x);
   return {Ub-lb+1};
}

int main(){
    vector<int> arr{1,2,3,4,5,5,6,7,7,7};
    int n=arr.size();
    int x;
    cin>>x;
    cout<<count(arr,n,x);
    return 0;
}