#include<bits/stdc++.h>
using namespace std;

int maxSubarraySum(vector<int> arr, int n) {
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            maxi = max(maxi, sum);
        }
    }
    return maxi;
}

long long maxSubarraySumOP(vector<int> arr, int n)
{
    long long maxi=LONG_MIN;
    long long sum=0;
    for( int i=0;i<n;i++){
        sum+=arr[i];

        if(sum>maxi) 
        maxi=sum;

        if(sum<0)  
        sum=0;
       
    }
     if(maxi<0) maxi=0;
    return maxi;
}

//to print all array elements
void maxSubarraySumELE(vector<int> arr, int n)
{
    long long maxi=LONG_MIN;
    long long sum=0;
    int index,istart,iend;
    for( int i=0;i<n;i++){
       if(sum==0){
          index=i;
        }
        sum+=arr[i];

        if(sum>maxi) {
        maxi=sum;
        istart=index;iend=i;
        }
      
        if(sum<0)  
        sum=0; 
    }
    for(int i=istart;i<=iend;i++)
    {
         cout<<arr[i]<<" ";
    }
}

int main(){
     vector<int> arr{1, 2, 7, -4, 3, 2, -10, 9, 1};
     maxSubarraySumELE(arr,arr.size());
    return 0;
}