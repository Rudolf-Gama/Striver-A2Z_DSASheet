#include<bits/stdc++.h>
using namespace std;
int missingK(vector < int > vec, int n, int k) {
    int low=0,high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        int miss=(vec[mid] - ( mid+1));
        if(miss<k)
        low=mid+1;
        else 
        high=mid-1;
    }
    return (high+k+1);
}

int missingKBF(vector < int > vec, int n, int k) {
  for(int i=0;i<n;i++){
    if(vec[i]<=k) k++;
    else 
     break;
  }
  return k;
}

int main(){
    vector<int>arr{2,4,5,6,7,9,11,12,13};
    int k;
    cin>>k;
    cout<<"Missing Number is "<<missingKBF(arr,arr.size(),k);
    return 0;
}