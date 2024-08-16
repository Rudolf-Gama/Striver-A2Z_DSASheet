#include<bits/stdc++.h>
using namespace std;
int search(vector<int>& arr, int n, int k)
{
       int l=0,h=n-1;
       while(l<=h){
            int mid=l+(h-l)/2;
            if(arr[mid]==k) 
            return mid;
            if(arr[l]<=arr[mid]){
                if(arr[l]<=k && k<=arr[mid]){
                    h=mid-1;
                }
                else l=mid+1;
            }
            else{
                if(arr[mid]<=k && k<=arr[h]){
                    l=mid+1;
                }
                else h=mid-1;
            }
        }
        return -1;
}

int main(){
    vector<int> arr{10,20,30,40,50,5,6,7,8};
    int k;
    cin>>k;
    cout<<"Index is "<<search(arr,arr.size(),k);
    return 0;
}