#include<bits/stdc++.h>
using namespace std;

bool searchInARotatedSortedArrayII(vector<int>&A, int key) {
    // Write your code here.
    int n=A.size();
    int l=0,h=n-1;
       while(l<=h){
            int mid=l+(h-l)/2;
            if(A[mid]==key) 
            return true;
            if(A[l]==A[mid]&&A[mid]==A[h]){
                l++;
                h--;
                continue;
            }
            if(A[l]<=A[mid]){
                if(A[l]<=key && key<=A[mid]){
                    h=mid-1;
                }
                else l=mid+1;
            }
            else{
                if(A[mid]<=key && key<=A[h]){
                    l=mid+1;
                }
                else h=mid-1;
            }
        }
        return false;
}


int main(){
    vector<int> arr{5,1,2,3,4,5,5,5,5};
    int k;
    cin>>k;
    cout<<"Index found "<<searchInARotatedSortedArrayII(arr,k);
    return 0;
}
