// Left Rotate an Array by One
#include<bits/stdc++.h>
using namespace std;
vector<int> rotateArray(vector<int>& arr, int n) {
    int temp=arr[0];
    for(int i=1;i<n;i++){
        arr[i-1]=arr[i];
    }
    arr[n-1]=temp;
    return arr;
}


int main(){
    vector<int> arr{2,4,6,5,9};
    arr=rotateArray(arr,arr.size());
    for(auto it: arr){
        cout<<it<<" ";
    }
    return 0; 
}