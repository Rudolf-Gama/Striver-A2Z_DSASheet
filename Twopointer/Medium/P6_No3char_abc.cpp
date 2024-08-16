#include<bits/stdc++.h>
using namespace std;
int countSubstring(string s) {
        // Code here
        int cnt=0;
        for(int i=0;i<s.length();i++){
            int hash[3]={0};
            for(int j=i;j<s.length();j++){
                hash[s[j]-'a']=1;
                if(hash[0]+hash[1]+hash[2]==3){
                    cnt+=(s.length()-j);
                    break;
                }
            }
        }
        return cnt ;
    }
    int countSubstring(string s) {
        // Code here
        int cnt=0;
         int hash[3]={-1,-1,-1};
        for(int i=0;i<s.length();i++){
           hash[s[i]-'a']=i;
          // if(hash[0]!=-1 && hash[1]!=-1 && hash[2]!=-1)
           cnt+=(1+min(hash[0],min(hash[1],hash[2])));
        }
        return cnt ;
    }
    int main(){
        string s="bacba";
        cout<<countSubstring(s);
    }