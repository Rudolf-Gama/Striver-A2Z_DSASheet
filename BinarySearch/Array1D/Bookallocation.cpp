#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
int calstu(vector<int>& arr, int n, int pages){
    int stu=1;
    long long nopages=0;
    for(int i=0;i<n;i++){
        if(nopages+arr[i]>pages){
               stu++;
            nopages=arr[i];
        }
        else{
           nopages+=arr[i];
        }
    }
   return stu;
}
int findPages(vector<int>& arr, int n, int m) {
    if(m>n) return -1;
     int low=*max_element(arr.begin(),arr.end());
    int high=accumulate(arr.begin(),arr.end(),0);
    while(low<=high){
       int mid=low+(high-low)/2;
        int stu=calstu(arr,n,mid);
        if(stu>m){
            low=mid+1;
        }
        else 
        high=mid-1;
    }
    return low;
}

int findPagesBF(vector<int>& arr, int n, int m) {
    if(m>n) return -1;
     int low=*max_element(arr.begin(),arr.end());
    int high=accumulate(arr.begin(),arr.end(),0);
    for(int i=low;i<=high;i++){
        int stu=calstu(arr,n,i);
        if(stu==m){
            return i;
        }
    }
    return low;
}


int main(){
    vector<int> arr{25,46,28,49,24};
    int m;
    cin>>m;
    cout<<"Minimum of max pages "<<findPages(arr,arr.size(),m);
    return 0;
}