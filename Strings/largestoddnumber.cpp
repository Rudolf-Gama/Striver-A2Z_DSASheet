#include<bits/stdc++.h>
using namespace std;

 string maxOdd(string s) {
        // your code here
        int n=s.length();
        for(int i=n-1;i>=0;i--){
            if((s[i]-'0')%2!=0)
             return s.substr(0,i+1);
        }
        return "";
    }


int main(){
  string s;
  cin>>s;
  cout<<maxOdd(s);
  return 0;
}