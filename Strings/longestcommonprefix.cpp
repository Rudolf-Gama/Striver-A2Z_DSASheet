#include<bits/stdc++.h>
using namespace std;

  string longestCommonPrefix(int n, string arr[]) {
        // your code here
        sort(arr,arr+n);
        string first=arr[0];
        string last=arr[n-1];
        string ans;
        for(int i=0;i<first.size();i++){
            if(first[i]!=last[i])
            break;
            ans+=first[i];
        }
        return !ans.empty() ? ans : "-1";
    }

    string longestCommonPrefixBP(int n, string arr[]) {
        // your code here
        if(n==0) return "-1";
        string pre=arr[0];
        for(int i=1;i<n;i++){
           while(arr[i].find(pre)!=0){
               pre=pre.substr(0,pre.length()-1);
               if(pre.empty())
               return "-1";
           } 
        }
        return pre;
    }

    
    int main(){
        int n=3;
        string arr[n]={"flower","flow","flight"};
        string ans=longestCommonPrefix(n,arr);
        cout<<ans;
        return 0;
    }