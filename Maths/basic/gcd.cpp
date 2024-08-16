#include<bits/stdc++.h>
using namespace std;

void gcd(int a,int b){
  for(int i=min(a,b);i>=1;i--){
    if(a%i==0 && b%i==0){
     cout<<"Gcd is "<<i;
     break;
     }
  }
}
void gcd1(int a,int b){
  if(a>0 && b>0){
    if(a>b) a=a%b;
    else b%=a;
  }
  if(a==0) cout<<"GCD is "<<b;
  else cout<<"GCD is "<<a;
}
int main(){
    int a,b;
    cin>>a>>b;
    // gcd(a,b);
    gcd1(a,b);
    return 0;
}