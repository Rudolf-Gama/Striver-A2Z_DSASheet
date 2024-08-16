#include<bits/stdc++.h>
using namespace std;

void selection(int a[],int n){
    for(int i=0;i<=n-2;i++){
        int min=i;
        for(int j=i;j<n;j++){
            if(a[j]<a[min]) min=j;
        }
        int temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    selection(a,n);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    return 0;
}