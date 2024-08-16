#include<bits/stdc++.h>
using namespace std;
string smallestWindow (string s, string p)
    {
        // Your code here
        int n=s.length();
        int m=p.length();
        int sindex=-1;
        int minlen=INT_MAX;
        for(int i=0;i<n;i++){
            int hash[256]={0};
            int cnt=0;
           for(int j=0;j<m;j++){
               hash[p[j]]++;
           } 
           for(int k=i;k<n;k++){
               if(hash[s[k]]>0) cnt++;
               hash[s[k]]--;
               if(cnt==m){
                   if((k-i+1)<minlen){
                       minlen=k-i+1;
                       sindex=i;
                       break;
                   }
               }
           }
        }
        return sindex==-1 ? "" : s.substr(sindex,minlen);
    }
    string smallestWindowOP(string s, string p)
    {
        // Your code here
        int n=s.length();
        int m=p.length();
        int sindex=-1;
        int minlen=INT_MAX;
        int hash[256]={0};
        int cnt=0,l=0,r=0;
        for(int j=0;j<m;j++){
            hash[p[j]]++;
        } 
        while(r<n){
          if(hash[s[r]]>0) cnt++;
          hash[s[r]]--;
          while(cnt==m){
             if(r-l+1<minlen){
                 minlen=r-l+1;
                 sindex=l;
             } 
            hash[s[l]]++;
            if(hash[s[l]]>0) cnt--;
            l++;
          }
          r++;
        }
        return sindex==-1 ? "-1" : s.substr(sindex,minlen);
    }
    int main(){
        string s="timetopractice";
        string p="toc";
        cout<<smallestWindow(s,p);
        return 0;
    }