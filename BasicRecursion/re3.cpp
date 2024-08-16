#include<bits/stdc++.h>
using namespace std;
//parameterized way
void sum1(int i,int sum){
    if(i<1){
        cout<<sum;
        return;
    }
    sum1(i-1,sum+i);
}

//functional way
int sum(int n){
    if(n==0) return 0;
    return n+sum(n-1);
}

int fact(int n){
    if(n==1 || n==0) return 1;
    return n*fact(n-1);
}
int main(){
    int n;
    cin>>n;
  //  sum1(n,0);
    //  cout<<sum(n);
     cout<<fact(n);
    return 0;
}