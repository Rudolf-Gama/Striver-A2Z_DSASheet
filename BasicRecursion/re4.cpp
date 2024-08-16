#include<bits/stdc++.h>
using namespace std;

void revarr1(int l,int r,int a[],int n){
if(l>=r) return ;
swap(a[l],a[r]);
revarr1(l+1,r-1,a,n);
}

void revarr2(int l,int a[],int n){
if(l>=n/2) return ;
swap(a[l],a[n-l-1]);
revarr2(l+1,a,n);
}

int main(){
    int n;
    cout<<"Enter the size"<<endl;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    //revarr1(0,n-1,a,n);
    revarr2(0,a,n);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    return 0;
}
