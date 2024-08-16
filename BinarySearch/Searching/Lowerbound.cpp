#include<bits/stdc++.h>
using namespace std;

// Search the index of a number  x same as lower bound
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

int main(){
    vector<int> arr{2,4,5,6,6,7,9,10};
    int x;
    cin>>x;
    cout<<"Index of lower bound is "<<lowerBound(arr,arr.size(),x);
    return 0;
}