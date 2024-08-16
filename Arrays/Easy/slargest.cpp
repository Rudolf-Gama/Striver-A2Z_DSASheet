#include<bits/stdc++.h>
using namespace std;


int SecondLargest(vector<int> &a,int n){
    int slargest=-1,largest=a[0];
    for(int i=0;i<n;i++){
        if(a[i]>largest){
            slargest=largest;
            largest=a[i];
        }
        else if(a[i]<largest && a[i]>slargest){
            slargest=a[i];
        }
    }
    return slargest;
}
int SecondSmallest(vector<int> &a,int n){
    int ssmallest=INT_MAX;
    int smallest=a[0];
    for(int i=0;i<n;i++){
        if(a[i]<smallest){
            ssmallest=smallest;
            smallest=a[i];
        }
        else if(a[i]>smallest && a[i]<ssmallest){
            ssmallest=a[i];
        }
    }
    return ssmallest;
}
int main(){
    vector<int> v{2,4,66,88,64,34};
    cout<<SecondLargest(v,v.size())<<endl;
    cout<<SecondSmallest(v,v.size());
    return 0; 
}