#include<bits/stdc++.h>
using namespace std;

int pivot(int a[],int low,int high){
    int pi=a[low];
    int i=low,j=high;
    while(i<j){
        while(a[i]<=pi && i<high)
        { i++;}
        while(a[j]>pi && j>low)
        { j--;}
        if(i<j){
           swap(a[i],a[j]);
        }
    }  
    swap(a[j],a[low]);
    return j;    
}
 void quicksort(int a[],int low,int high){
    if(low<high){
        int p=pivot(a,low,high);
        quicksort(a,low,p-1);
        quicksort(a,p+1,high);
    }
 }
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    quicksort(a,0,n-1);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    return 0; 
}