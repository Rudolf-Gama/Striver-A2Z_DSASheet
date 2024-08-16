#include<bits/stdc++.h>
using namespace std;

long long trappingWaterBP(int arr[], int n){
        // code here
        int prefix[n],suffix[n];
        long long total=0L;
        prefix[0]=arr[0];
        for(int i=1;i<n;i++){
            prefix[i]=max(arr[i],prefix[i-1]);
        }
        suffix[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i]=max(arr[i],suffix[i+1]);
        }
        
        for(int i=0;i<n;i++){
            int lmax=prefix[i],rmax=suffix[i];
            if(arr[i]<lmax && arr[i]<rmax){
                total+=min(lmax,rmax)-arr[i];
            }
        }
        return total;
    }

long long trappingWater(int arr[], int n){
        // code here
        int l=0,r=n-1;
        int lmax=0,rmax=0;
        long long total=0L;
        while(l<r){
            if(arr[l]<=arr[r]){
                if(lmax>arr[l]){
                    total+=lmax-arr[l];
                }
                else lmax=arr[l];
                l++;
            }
            else{
                if(rmax>arr[r]){
                    total+=rmax-arr[r];
                }
                else rmax=arr[r];
                r--;
            }
        }
        return total;
    }
    int main(){
        int arr[]={3,0,0,1,0,4};
        int n=sizeof(arr)/sizeof(arr[0]);
        cout<<trappingWater(arr,n);
        return 0;
    }