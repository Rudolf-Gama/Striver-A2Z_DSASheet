#include<bits/stdc++.h>
using namespace std;
int c=0;
void name(int n){
    if(c==n) return;
    else{
        cout<<"Rudolf"<<endl;
        c++;
        name(n);
    }
}
void na(int i,int n){
    if(i>n) return ;
    cout<<"Rudolf"<<endl;
    na(i+1,n);
}
void na2(int i,int n){
    if(i<1) return ;
    cout<<i<<endl;
    na2(i-1,n);
}
//backtracing 
//1->n
void ba1(int i,int n){
    if(i<1) return;
    ba1(i-1,n);
    cout<<i<<" ";
}
//n->1
void ba2(int i,int n){
    if(i>n) return;
    ba2(i+1,n);
    cout<<i<<" ";
}

int main(){
    int n;
    cin>>n;
    // name(n);
    //na(1,n);
    //na2(n,n);
    // ba1(n,n);
    ba2(1,n);
    return 0;
}