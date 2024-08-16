#include<bits/stdc++.h>
using namespace std;
vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        unordered_map<long long int,int>mpp;
        for(long long int i=0;i<N;i++){
            mpp[Arr[i]]++;
        }
        vector<long long int>ans;
        for(auto it:mpp)
        {
            if(it.second&1)
            ans.push_back(it.first);
        }
        sort(ans.begin(),ans.end(),greater<int>());
        return ans;
    }
    
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        long long int xorr=0;
        for(auto i=0;i<N;i++){
            xorr=xorr^Arr[i];
        }
        long long int r=(xorr&(xorr-1))^(xorr);
        long long int b1=0,b2=0;
        for(auto i=0;i<N;i++){
            if(Arr[i]&r)
            b1=b1^Arr[i];
            else
            b2=b2^Arr[i];
        }
        vector<long long int> ans={b1,b2};
        sort(ans.begin(),ans.end(),greater<int>());
        return ans;
    }

int main(){
    long long int Arr[]={4, 2, 4, 5, 2, 3, 3, 1};
    long long int size=sizeof(Arr)/sizeof(Arr[0]);
    vector<long long int> ans=twoOddNum(Arr,size);
    for(auto it: ans) cout<<it<<" ";
    return 0;
}