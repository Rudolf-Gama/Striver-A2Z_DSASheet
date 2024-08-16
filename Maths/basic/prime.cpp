#include<bits/stdc++.h>
using namespace std;
//O(n)
void prime(int n){
    int c=0;
    for(int i=1;i<=n;i++){
        if(n%i==0) c++;
    }
    if(c==2) cout<<"Prime";
    else cout<<"Not prime";
}

void primeb(int n){
    int c=0;
    for(int i=1;i*i<=n;i++){
        if(n%i==0) c++;
        if(n/i!=i) c++;
    }
    if(c==2) cout<<"Prime";
    else cout<<"Not Prime";
}

int main(){
int n;
cout<<"Enter the Number"<<endl;
cin>>n;
// prime(n);
primeb(n);
return 0;
}