#include<bits/stdc++.h>
using namespace std;

void revnum(int n){
  int r=0,d=0;
  while(n>0){
    d=n%10;
    r=r*10+d;
    n=n/10;
  }
  cout<<r;
}
int main(){
    int n;
    cin>>n;
    revnum(n);
    return 0;
}