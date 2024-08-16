#include<bits/stdc++.h>
using namespace std;
 int longestUniqueSubsttrBP(string S){
        //code
        int maxlen=0;
        for(int i=0;i<S.size();i++){
              int hash[256]={0};
            for(int j=i;j<S.size();j++){
                if(hash[S[j]]==1){
                    break;
                }
                hash[S[j]]=1;
                maxlen=max(maxlen,j-i+1);
            }
        }
        return maxlen;
    }
int longestUniqueSubsttr(string S){
        //code
        int n=S.length();
        int maxlen=0;
        int l=0,r=0;
        int hash[256];
        for(int i=0;i<n;i++) hash[S[i]]=-1;
        while(r<n){
            if(hash[S[r]]!=-1){
                if(hash[S[r]]>=l){
                    l=hash[S[r]]+1;
                }
            }
            maxlen=max(maxlen,r-l+1);
            hash[S[r]]=r;
            r++;
        }
        return maxlen;
    }
    int main(){
      string str="geeksforgeeks";
      cout<<longestUniqueSubsttrBP(str);
      return 0;
    }