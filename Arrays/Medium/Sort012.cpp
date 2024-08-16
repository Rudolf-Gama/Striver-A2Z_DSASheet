#include<bits/stdc++.h>
using namespace std;


 void sort012OP(vector<int>& a, int n)
    {
    int low=0,mid=0,high=n-1;
    while(mid<=high){
        if(a[mid]==0){
           swap(a[mid++],a[low++]);
    
        } else if (a[mid] == 1) {
            mid++;
        } else {
           swap(a[mid], a[high--]);
        }
    }
    }


 void sort012(vector<int>& a, int n)
    {
    int cnt0=0,cnt1=0,cnt2=0;
    for(int i=0;i<n;i++){
       if(a[i]==0) cnt0++;
       else if(a[i]==1) cnt1++;
       else cnt2++;
    }
    for(int i=0;i<cnt0;i++) a[i]=0;
    for(int i=cnt0;i<(cnt0+cnt1);i++) a[i]=1;
    for(int i=cnt0+cnt1;i<n;i++) a[i]=2;
    }

    int main(){
        vector<int> a{0,1,2,1,2,1,0,0,0,2,2};
        sort012(a,a.size());
        for(auto it: a) cout<<it<<" ";
        return 0;
    }