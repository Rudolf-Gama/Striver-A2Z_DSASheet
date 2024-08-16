#include<bits/stdc++.h>
using namespace std;
int singleBP(vector<int> arr,int n){
    unordered_map<long long int,int>mpp;
        for(long long int i=0;i<n;i++){
            mpp[arr[i]]++;
        }
        for(auto it:mpp)
        {
            if(it.second==1)
            return it.first;
        }
}
int singleB(vector<int> arr,int n){
    int ans=0;
    for(int b=0;b<32;b++){
        int cnt=0;
        for(int i=0;i<n;i++){
            if(arr[i]&(1<<b))
            cnt++;
        }
        if(cnt%3==1)
         ans=ans|(1<<b);
    }
    return ans;
}


int singleOP1(vector<int> arr,int n){
    int one=0,two=0;
    for(int i=0;i<n;i++){
        one=(arr[i]^one)&(~(two));
        two=(arr[i]^two)&(~(one));
    }
    return one;
}
int singleOP2(vector<int> arr,int n){
    sort(arr.begin(),arr.end());
    for(int i=1;i<n;i=i+3){
        if(arr[i]!=arr[i-1])
        return arr[i-1];
    }
    return arr[n-1];
}

int main(){
    vector<int>arr{2,2,4,5,7,8,5,7,8,5,7,8,2};
    cout<<singleB(arr,arr.size());
    return 0;
}