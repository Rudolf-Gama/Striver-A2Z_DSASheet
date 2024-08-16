#include<bits/stdc++.h>
using namespace std;
   int characterReplacement(string S, int K) {
      // code here
        int maxlen=0;
        for(int i=0;i<S.length();i++){
            int hash[26]={0};
            int maxfre=0;
            for(int j=i;j<S.length();j++){
                hash[S[j]-'A']++;
                maxfre=max(maxfre,hash[S[j]-'A']);
                int changes=(j-i+1)-maxfre;
                if(changes<=K){
                    maxlen=max(maxlen,j-i+1);
                }
                else break;
            }
        }
        return maxlen;
    }
int characterReplacementBP(string S, int K) {
        // code here
        int maxlen=0;
        int hash[26]={0};
        int maxfre=0;
        int l=0,r=0;
        while(r<S.length())
        {
            hash[S[r]-'A']++;
            maxfre=max(maxfre,hash[S[r]-'A']);
            int changes=((r-l+1)-maxfre);
            while(changes>K){
                hash[S[l]-'A']--;
                l++;
                changes=((r-l+1)-maxfre);
            }
            if(changes<=K){
                maxlen=max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;
    }
    int characterReplacementOP(string S, int K) {
        // code here
        int maxlen=0;
        int hash[26]={0};
        int maxfre=0;
        int l=0,r=0;
        while(r<S.length())
        {
            hash[S[r]-'A']++;
            maxfre=max(maxfre,hash[S[r]-'A']);
            int changes=((r-l+1)-maxfre);
            if(changes>K){
                hash[S[l]-'A']--;
                l++;
                changes=((r-l+1)-maxfre);
            }
            if(changes<=K){
                maxlen=max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;
    }
    int main(){
        string s="AAABABABA";
        int k;
        cin>>k;
        cout<<characterReplacement(s,k);
        return 0;
    }