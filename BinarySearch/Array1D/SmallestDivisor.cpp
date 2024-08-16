#include<bits/stdc++.h>
using namespace std;

bool divisor(vector<int>& arr, int mid,int limit){
	int n=arr.size();
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=ceil((double)arr[i]/(double)mid);
	}
	if(sum<=limit)
	return true;
	else return false;
}
int smallestDivisor(vector<int>& arr, int limit)
{
	int n=arr.size();
	if(n>limit) return -1;
	int  maxi=INT_MIN;
	for(int i=0;i<n;i++){
       maxi=max(maxi,arr[i]);
	}

	int low=1,high=maxi;
	while(low<=high){
		int mid=low+(high-low)/2;
		if(divisor(arr,mid,limit))
		  high=mid-1;
		  else 
		  low=mid+1;
	}
	return low;
}


int smallestDivisorBF(vector<int>& arr, int limit)
{
	int n=arr.size();
	if(n>limit) return -1;
	int  maxi=INT_MIN;
	for(int i=0;i<n;i++){
       maxi=max(maxi,arr[i]);
	}
   	for(int i=1;i<=maxi;i++){
		if(divisor(arr,i,limit))
		return i;
	} 
}


int main(){
    vector<int> arr{1, 2, 3, 4, 5};
    int limit;
    cin>>limit;  //8
    cout<<smallestDivisor(arr,limit);
    return 0;
}