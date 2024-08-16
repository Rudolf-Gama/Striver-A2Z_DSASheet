#include<bits/stdc++.h>
using namespace std;

void armstrong(int n){
  int r=0,d=0,temp=n;int c=(int)(log10(n)+1);
  while(n>0){
    d=n%10;
    r=r+pow(d,c);
    n=n/10;
  }
  if(temp==r) cout<<"armstrong";
  else cout<<"Not armstrong";
}
int main(){
    int n;
    cin>>n;
    armstrong(n);
    return 0;
}