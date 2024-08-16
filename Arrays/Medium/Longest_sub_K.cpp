#include<bits/stdc++.h>
using namespace std;

//both positive and negative
int longestSubarrayWithSumK(vector<int> a, long long k) {
    long long sum=0;
    int n=a.size();
    map<long long,int> mpp;
    int length=0;
    for(int i=0;i<n;i++){
    sum+=a[i];
    if(sum==k) {
        length=max(length,i+1);
    }
    long long rem=sum-k;
    if(mpp.find(rem)!=mpp.end()){
        int l=i-mpp[rem];
        length=max(length,l);
    }
    if(mpp.find(sum)==mpp.end()){
        mpp[sum]=i;
    }
    }
 return length;
}

//only positives optimised
int longestSubarrayWithSumKOP(vector<int> a, long long k) {
    long long sum=a[0];
    int n=a.size();
    int length=0;
    int left=0,right=0;
    while(right<n){
         while(left<=right && sum>k){
             sum-=a[left++];
         }
         if(sum==k) length=max(length,right-left+1);
         sum+=a[++right];
    }
 return length;
}


int main(){
    vector<int> a{1, 2, 3, 1, 1, 1, 1,2};
    int k;
    cin>>k;
    int ans=longestSubarrayWithSumKOP(a,k);
    cout<<ans;
    return 0;
}