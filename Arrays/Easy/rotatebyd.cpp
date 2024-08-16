#include<bits/stdc++.h>
using namespace std;

vector<int> rotateArray(vector<int>arr, int k) {
    int n=arr.size();
    k=k%n;
    vector<int> temp;
    for(int i=0;i<k;i++){
        temp.push_back(arr[i]);
    }
    for(int i=k;i<n;i++){
        arr[i-k]=arr[i];
    }
    for(int i=0;i<k;i++){
        arr[n-k+i]=temp[i];
    }
    return arr;
}

vector<int> rotateArray1(vector<int>arr, int k) {
int n=arr.size();
k=k%n;
   reverse(arr.begin(),arr.begin()+k);
   reverse(arr.begin()+k,arr.end());
   reverse(arr.begin(),arr.end());
   return arr;
}

int main(){
    vector<int> arr{2,4,6,5,9};
    int k;
    cin>>k;
    arr=rotateArray1(arr,k);
    for(auto it: arr){
        cout<<it<<" ";
    }
    return 0; 
}