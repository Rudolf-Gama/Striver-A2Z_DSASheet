#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter the size"<<endl;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];

    int hash[13]={0};
    for(int i=0;i<n;i++) hash[a[i]]+=1;

    cout<<"Enter the queries"<<endl;
    int q;
    cin>>q;
    while(q--){
        int num;
        cin>>num;
        //fetch
        cout<<"Frequency of "<<num<<"is "<<hash[num]<<endl;
    }
    return 0;
}
