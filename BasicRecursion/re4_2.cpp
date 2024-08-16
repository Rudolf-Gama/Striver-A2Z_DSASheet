#include<bits/stdc++.h>
using namespace std;

bool palin(int i,int n,string s){
    if(i>=n/2) return true;
    if(s[i]!=s[n-i-1]) return false;
    return palin(i+1,n,s);
}
int main(){
     string str;
     cin>>str;
     int n=str.size(); //length()
      bool b=palin(0,n,str);
      if(b==true) cout<<"Palindrome";
      else cout<<"Not palindrome";
    return 0;
}