#include<bits/stdc++.h>
using namespace std;

bool isAnagram(string a, string b){
        // Your code here
        int hash[26]={0};
        for(int i=0;i<a.length();i++)
        hash[a[i]-'a']++;
        for(int i=0;i<b.length();i++)
        hash[b[i]-'a']--;
        
        for(int i=0;i<26;i++)
        {
            if(hash[i]!=0)
             return false;
        }
        return true;
    }
    
    bool isAnagramBP(string a, string b){
        if(a.length()!=b.length()) return false;
        
       sort(a.begin(),a.end());
       sort(b.begin(),b.end());
       for(int i=0;i<a.size();i++){
           if(a[i]!=b[i]) return false;
       }
       return true;
    }

    int main(){
        string a,b;
        cin>>a>>b;
        cout<<isAnagram(a,b);
        return 0;
    }