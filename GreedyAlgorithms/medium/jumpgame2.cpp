#include<bits/stdc++.h>
using namespace std;
/*
 int minimumjumps(int arr[],int ind,int jumps,int n){

        if(ind>=n-1) return jumps;
        int mini=INT_MAX;
        for(int i=1;i<=arr[ind];i++){
            mini=min(mini,minimumjumps(arr,ind+i,jumps+1,n));
        }
        return mini;
    }
    
    int minJumps(int arr[], int n){
        // Your code here
        if(n<=1) return 0;
        if(arr[0]==0) return -1;
        return minimumjumps(arr,0,0,n);
    }
    The above might not be correct kindly verify it
*/

 int minJumps(int arr[], int n){
        // Your code here
        if(n<=1) return 0;
        
        if(arr[0]==0) return -1;
        
        int l=0,r=0,jumps=0;
        while(r<n-1){
            int far=0;
            for(int i=l;i<=r;i++){
                far=max(far,i+arr[i]);
            }
            if(far<=r)
            return -1;
            
            l=r+1;
            r=far;
            jumps++;
        }
        return jumps;
    }

int main() {
    int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout <<minJumps(arr, n);
    return 0;
}