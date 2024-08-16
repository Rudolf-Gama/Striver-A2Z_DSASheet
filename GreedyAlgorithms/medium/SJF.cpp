#include<bits/stdc++.h>
using namespace  std;
long long solve(vector<int>& bt) {
        // code here
        sort(bt.begin(),bt.end());
        int n=bt.size();
        int t=0,wt=0;
        for(int i=0;i<n;i++){
            wt+=t;
            t+=bt[i];
        }
        return (long long)(wt/n);
    }
    int main(){
        vector<int>bt{4,3,7,1,2};
        cout<<solve(bt)<<endl;
        return 0;
    }