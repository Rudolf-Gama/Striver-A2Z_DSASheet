#include<bits/stdc++.h>
using namespace std;

void insertion(int a[],int n){
    for(int i=0;i<n;i++){
        int j=i;
        while(j>0 && a[j-1]>a[j]){
        int temp=a[j-1];
        a[j-1]=a[j];
        a[j]=temp;
        j--;
        }   
    }
}
void insertionr(int a[],int i,int n){
    if(n==i) return;
        int j=i;
        while(j>0 && a[j-1]>a[j]){
        int temp=a[j-1];
        a[j-1]=a[j];
        a[j]=temp;
        j--;
        } 
        insertionr(a,i+1,n);
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    insertionr(a,0,n);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    return 0;
}