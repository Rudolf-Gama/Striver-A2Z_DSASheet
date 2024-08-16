#include<bits/stdc++.h>
using namespace std;

bool areIsomorphic(string str1, string str2)
    {
        // Your code here
        if(str1.length()!=str2.length()) return false;
        unordered_map<char,char>mpp1,mpp2;
        
        for(int i=0;i<str1.length();i++){
            char c1=str1[i];
            char c2=str2[i];
            
            if(mpp1.find(c1)!=mpp1.end()){
                if(mpp1[c1]!=c2) return false;
            }
             if(mpp2.find(c2)!=mpp2.end()){
                if(mpp2[c2]!=c1) return false;
            }
            mpp1[c1]=c2;
            mpp2[c2]=c1;
        }
        return true;
    }

    int main(){
        string str1,str2;
        cin>>str1>>str2;
        cout<<areIsomorphic(str1,str2);
        return 0;
    }