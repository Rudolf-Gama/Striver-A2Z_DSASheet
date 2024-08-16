#include<bits/stdc++.h>
using namespace std;

void palindrome(int n){
  int r=0,d=0,temp=n;
  while(n>0){
    d=n%10;
    r=r*10+d;
    n=n/10;
  }
  if(temp==r) cout<<"Palindrome";
  else cout<<"Not Palindrome";
}
int main(){
    int n;
    cin>>n;
    palindrome(n);
    return 0;
}