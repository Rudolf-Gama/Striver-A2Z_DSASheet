#include<bits/stdc++.h>
using namespace std;

  int maxChildren(int N, int M, vector<int> &greed, vector<int> &sz) {
        // code here
        sort(greed.begin(),greed.end());
        sort(sz.begin(),sz.end());
        int l=0,r=0;
        while(l<N && r<M){
            if(greed[l]<=sz[r])
            l++;
            r++;
        }
        return l;
    }
    
    int main(){
        vector<int>greed{1,5,3,3,4};
        vector<int>sz{4,2,1,2,1,3};
        cout<<maxChildren(greed.size(),sz.size(),greed,sz);
        return 0;
    }