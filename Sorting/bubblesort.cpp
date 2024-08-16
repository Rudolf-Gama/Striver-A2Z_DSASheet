#include<bits/stdc++.h>
using namespace std;

void bubble(int a[],int n){
    for(int i=n-1;i>=1;i--){
        int s=0;
        for(int j=0;j<=i-1;j++){
            if(a[j]>a[j+1]) {
                int temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
                s++;
            }
        }
        if(s==0) break;
    }
}
void bubbleb(int a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){    
            if(a[j]>a[j+1]) {
                int temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
    }
}
void bubbler(int a[],int n){
     if(n==1) return;
        for(int j=0;j<n-1;j++){    
            if(a[j]>a[j+1]) {
                int temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
        bubbler(a,n-1);
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    bubbler(a,n);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    return 0;
}