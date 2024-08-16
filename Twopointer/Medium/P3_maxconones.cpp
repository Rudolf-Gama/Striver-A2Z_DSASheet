#include<bits/stdc++.h>
using namespace std;
 int findZeroesBF(int arr[], int n, int m) {
        // code here
        int maxlen=0;
        for(int i=0;i<n;i++){
            int zero=0;
            for(int j=i;j<n;j++){
                if(arr[j]==0) zero++;
                if(zero>m) break;
                 maxlen=max(maxlen,j-i+1);
            }
        }
        return maxlen;
    } 
 int findZeroesBP(int arr[], int n, int m) {
        // code here
        int maxlen=0;
        int l=0,r=0,zero=0;
        while(r<n){
            if(arr[r]==0) zero++;
            while(zero>m){
                if(arr[l]==0) zero--;
                l++;
            }
            if(zero<=m){
                maxlen=max(maxlen,r-l+1);
            }
            r++;
         }
         return maxlen;
    } 

    int findZeroesOP(int arr[], int n, int m) {
        // code here
        int maxlen=0;
        int l=0,r=0,zero=0;
        while(r<n){
            if(arr[r]==0) zero++;
            if(zero<=m){
                maxlen=max(maxlen,r-l+1);
            }
            else{
                if(arr[l]==0) zero--;
                l++;
            }
            r++;
         }
         return maxlen;
    }  
int main(){
 int arr[]={1,1,1,1,0,0,1,1,1,0,0};
 int n=sizeof(arr)/sizeof(arr[0]);
 int k;
 cin>>k;
 cout<<findZeroesOP(arr,n,k);
 return 0;
}