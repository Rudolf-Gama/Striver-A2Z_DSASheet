#include<bits/stdc++.h>
using namespace std;
int converttodecimal(string str){
    int n=0,p=1;
    int len=str.length();
    for(int i=len-1;i>=0;i--){
        if(str[i]=='1')
             n+=p;
        p*=2;
    }
    return n;
}
int converttodecimalmy(string str){
    int n=0;
    int len=str.length();
    for(int i=len-1;i>=0;i--){
        if(str[i]=='1')
             n+=pow(2,len-i-1);
    }
    return n;
}
int main(){
    string str;
    cin>>str;
    cout<<converttodecimalmy(str);
    return 0;
}
