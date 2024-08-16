#include<bits/stdc++.h>
using namespace std;
void countdigit(int n){
    int c=0;
    while(n>0){
        c++;
        n=n/10;
    }
    cout<<"The total number of digits are "<<c<<endl;
}
int count(int n){
    int c=(int)(log10(n)+1);
    return c;
}
int main(){
    int n;
    cout<<"Enter the number"<<endl;
    cin>>n;
    countdigit(n);
    cout<<count(n);
    return 0;
}