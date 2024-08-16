#include<bits/stdc++.h>
using namespace std;
string convertbinary(int x){
    string s="";
    while(x>=1){
        if(x%2==1)
          s+='1';
        else
          s+='0';
       x=x/2;
    }
    reverse(s.begin(),s.end());
    return s;
}

int main(){
    int x;
    cin>>x;
    string s=convertbinary(x);
    cout<<s;
    return 0;
}
