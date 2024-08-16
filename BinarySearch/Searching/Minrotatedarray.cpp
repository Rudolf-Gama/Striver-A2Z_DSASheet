#include<bits/stdc++.h>
using namespace std;

int findMin(vector<int>& arr)
{
	// Write your code here.
	int n=arr.size();
	int low=0;
	int high=n-1;
	int mini=INT_MAX;
	while(low<=high){
		int mid=low+(high-low)/2;
        if(arr[low]<=arr[high]){
			mini=min(arr[low],mini);
		   return mini; //break
		}
		else if(arr[mid]>=arr[low]){
			mini=min(arr[low],mini);
			low=mid+1;
		}
		else{
			mini=min(arr[mid],mini);
			high=mid-1;
		}
	}
	return mini;
}

int findMinDUP(vector<int>& arr)
{
	int n=arr.size();
	int low=0;
	int high=n-1;
	int mini=INT_MAX;
	while(low<=high){
		int mid=low+(high-low)/2;
        if(arr[low]==arr[mid] && arr[mid]==arr[high]){
            mini=min(arr[low],mini);
            low++,high--;
            continue;
        }
	    if(arr[mid]>=arr[low]){
			mini=min(arr[low],mini);
			low=mid+1;
		}
		else{
			mini=min(arr[mid],mini);
			high=mid-1;
		}
	}
	return mini;
}
int main(){
    vector<int> arr{3,4,4,4,4,4,4,1,2,3,3,3,3};
    cout<<findMinDUP(arr);
    return 0;
}