#include<bits/stdc++.h>
using namespace std;
 	void pushZerosToEnd(int arr[], int n) {
	    int low=0,mid=0,high=n-1;
	    while(mid<=high){
	        if(arr[mid]!=0){
	            swap(arr[low],arr[mid]);
	            low++;
	            mid++;
	        }
	        else mid++;
	    }
	}
int main(){
    int arr[]={0,3,4,5,0,7,0,0,3,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
     pushZerosToEnd(arr,n);
     for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}