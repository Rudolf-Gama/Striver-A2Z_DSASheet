#include<bits/stdc++.h>
using namespace std;

int findKRotation(vector<int> &arr){ 
    int n=arr.size();
	int low=0;
	int high=n-1;
    int index=-1;
	int mini=INT_MAX;
	while(low<=high){
		int mid=low+(high-low)/2;
        if(arr[low]<=arr[high]){
			if(arr[low]<mini){
                mini=arr[low];
                index=low;
            }
		   return index;//break
		}
	   if(arr[mid]>=arr[low]){
				if(arr[low]<mini){
                mini=arr[low];
                index=low;
            }
			low=mid+1;
		}
		else{
				if(arr[mid]<mini){
                mini=arr[mid];
                index=mid;
            }
			high=mid-1;
		}
	}
	return index;  
}
int main(){
    vector<int> arr{4,5,6,7,1,2,3};
    cout<<findKRotation(arr);
    return 0;
}