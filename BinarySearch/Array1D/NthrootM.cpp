#include<bits/stdc++.h>
using namespace std;
int root(int mid,int n,int m){
  long long int ans=1;
 for(int i=1;i<=n;i++){
    ans=ans*mid;
    if(ans>m) return 2; 
 }
   if(ans==m) return 1;
   return 0;
}
int NthRoot(int n, int m) {
   int low=1,high=m;
  while(low<=high){
   int mid=low+(high-low)/2;
    int ans=root(mid,n,m);
    if(ans==1){
      return mid;
    }
    else if(ans==2)
      high=mid-1;
      else {
        low=mid+1;
      }
  }
  return -1;
}
int main(){
    int n,m;
    cout<<"Enter the root";
    cin>>n;
    cout<<"Enter the Number";
    cin>>m;
    cout<<NthRoot(n,m);
    return 0;
}