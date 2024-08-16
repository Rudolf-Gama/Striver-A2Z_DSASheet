#include<bits/stdc++.h>
using namespace std;
int lowerBound(vector<int> arr, int n, int x) {
	int low=0;
	int high=n-1;
	int ans=n;
	while(low<=high){
		int mid=low+(high-low)/2;
		if(arr[mid]>=x){
			ans=mid;
			high=mid-1;
		}
		else 
		 low=mid+1;
	}
	return ans;
}
int UpperBound(vector<int> arr, int n, int x) {
	int low=0;
	int high=n-1;
	int ans=n;
	while(low<=high){
		int mid=low+(high-low)/2;
		if(arr[mid]>x){
			ans=mid;
			high=mid-1;
		}
		else 
		 low=mid+1;
	}
	return ans;
}
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
   int lb=lowerBound(arr,n,k);
   if(lb==n || arr[lb]!=k) return {-1,-1};
   int hb=UpperBound(arr,  n, k);
   return {lb,hb-1};
}


//using BInary search find first and last occurance

int firstOcc(vector<int>&arr, int n, int x) {
	int low=0, high=n-1;
	int first=-1;
	while(low<=high){
		int mid=(high+low)/2;
		if(arr[mid]==x){
			first=mid;
			high=mid-1;
		}
        else if(arr[mid]>x)
            high=mid-1;
		else 
		 low=mid+1;
	}
	return first;
}
int lastOcc(vector<int>& arr, int n, int x) {
	int low=0,high=n-1;
	int last=-1;
	while(low<=high){
		int mid=(high+low)/2;
	    if(arr[mid]==x){
			last=mid;
			low=mid+1;
		}
        else if(arr[mid]>x)
            high=mid-1;
		else 
		  low=mid+1;
	}
	return last;
}
pair<int, int> firstAndLastPositionBP(vector<int>& arr, int n, int k)
{
   int lb=firstOcc(arr,n,k);
   if(lb==-1) return {-1,-1};
   int Ub=lastOcc(arr,  n, k);
   return {lb,Ub};
}

int main(){
    vector<int> arr{1,2,4,5,6,6,6,7,8};
    int k;
    cin>>k;
    pair<int,int> ans=firstAndLastPositionBP(arr,arr.size(),k);
    cout<<"First index is "<<ans.first<<endl<<"Second index is "<<ans.second; 
    return 0;
}
