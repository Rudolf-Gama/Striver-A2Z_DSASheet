#include<bits/stdc++.h>
using namespace std;

int longestKSubstr(string s, int k) {
    // your code here
        int maxlen=0;
        unordered_map<char,int>mpp;
        for(int i=0;i<s.length();i++){
            mpp.clear();
            for(int j=i;j<s.length();j++){
                mpp[s[j]]++;
                if(mpp.size()<=k){
                    maxlen=max(maxlen,j-i+1);
                }
                else break;
            }
        }
        unordered_map<char,int>mpp1;
        for(int i=0;i<s.length();i++){
            mpp1[s[i]]++;
        }
        if(mpp1.size()<k)
        return -1;
        
        return maxlen;
    }
    
    int longestKSubstrBP(string s, int k) {
    // your code here
        int maxlen=0;
        int l=0,r=0;
        unordered_map<char,int>mpp;
        while(r<s.length()){
            mpp[s[r]]++;
            while(mpp.size()>k){
                mpp[s[l]]--;
                if(mpp[s[l]]==0) 
                mpp.erase(s[l]);
                l++;
            }
            if(mpp.size()<=k){
                maxlen=max(maxlen,r-l+1);
            }
            r++;
        }
        
        if(mpp.size()<k)
        return -1;
        
        return maxlen;
    }

    int longestKSubstrOP(string s, int k) {
    // your code here
        int maxlen=0;
        int l=0,r=0;
        unordered_map<char,int>mpp;
        while(r<s.length()){
            mpp[s[r]]++;
            if(mpp.size()>k){
                mpp[s[l]]--;
                if(mpp[s[l]]==0) 
                mpp.erase(s[l]);
                l++;
            }
            if(mpp.size()<=k){
                maxlen=max(maxlen,r-l+1);
            }
            r++;
        }
        
    
        if(mpp.size()<k)
        return -1;
        
        return maxlen;
    }
    
    int main(){
        string s="ssajsdjsaa";
        int k;
        cin>>k;
        cout<<longestKSubstr(s,k);
        return 0;
    }